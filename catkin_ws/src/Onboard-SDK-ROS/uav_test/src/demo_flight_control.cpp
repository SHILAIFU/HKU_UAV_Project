#include "uav_test/demo_flight_control.h"
#include "dji_sdk/dji_sdk.h"

#include "uav_test/Config.h"
#include "uav_test/pid.h"

const float deg2rad = C_PI / 180.0;
const float rad2deg = 180.0 / C_PI;

ros::ServiceClient set_local_pos_reference;
ros::ServiceClient sdk_ctrl_authority_service;
ros::ServiceClient drone_task_service;
ros::ServiceClient query_version_service;

ros::Publisher ctrlPosYawPub;
ros::Publisher ctrlBrakePub;

// global variables for subscribed topics
uint8_t flight_status = 255;
uint8_t display_mode = 255;
sensor_msgs::NavSatFix current_gps;

geometry_msgs::Quaternion current_atti;
geometry_msgs::Point current_local_pos;

// sensor_msgs::NavSatFix zero_gps_location;

Mission mymission;

Pid_control pid_x, pid_y, pid_z, pid_yaw;

float inputNumber_X, inputNumber_Y, inputNumber_Z, inputNumber_YAW;

bool info_flag = false;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo");
  ros::NodeHandle nh;

  // Subscribe to messages from dji_sdk_node
  ros::Subscriber attitudeSub = nh.subscribe("dji_sdk/attitude", 10, &attitude_callback);
  ros::Subscriber gpsSub = nh.subscribe("dji_sdk/gps_position", 10, &gps_callback);
  ros::Subscriber flightStatusSub = nh.subscribe("dji_sdk/flight_status", 10, &flight_status_callback);
  ros::Subscriber displayModeSub = nh.subscribe("dji_sdk/display_mode", 10, &display_mode_callback);
  ros::Subscriber localPosition = nh.subscribe("dji_sdk/local_position", 10, &local_position_callback);

  // Publish the control signal
  ctrlPosYawPub = nh.advertise<sensor_msgs::Joy>("dji_sdk/flight_control_setpoint_ENUposition_yaw", 10);
  ctrlBrakePub = nh.advertise<sensor_msgs::Joy>("dji_sdk/flight_control_setpoint_generic", 10);

  // Basic services
  sdk_ctrl_authority_service = nh.serviceClient<dji_sdk::SDKControlAuthority>("dji_sdk/sdk_control_authority");
  drone_task_service = nh.serviceClient<dji_sdk::DroneTaskControl>("dji_sdk/drone_task_control");
  query_version_service = nh.serviceClient<dji_sdk::QueryDroneVersion>("dji_sdk/query_drone_version");
  set_local_pos_reference = nh.serviceClient<dji_sdk::SetLocalPosRef>("dji_sdk/set_local_pos_ref");

  obtain_control();
  bool takeoff_result;

  pid_x.PID_init(1.5, 0, 0, 2, -1);
  pid_y.PID_init(1.5, 0, 0, 2, -1);
  pid_z.PID_init(0.4, 0, 0, 2, -1);
  pid_yaw.PID_init(0.4, 0, 0, 2, -2);

  if (!set_local_position()) // We need this for height
  {
    ROS_ERROR("GPS health insufficient - No local frame reference for height. Exiting.");
    return 1;
  }

  char inputChar;
  while (1)
  {
    std::cin >> inputChar;
    ros::spinOnce();
    switch (inputChar)
    {
    case 'a':
      set_local_position();
      ROS_INFO("M100 taking off!");
      takeoff_result = M100monitoredTakeoff();
      while (!takeoff_result)
        ;
      break;

    case 'd':
      std::cin >> inputNumber_X;
      std::cin >> inputNumber_Y;
      std::cin >> inputNumber_Z;
      std::cin >> inputNumber_YAW;
      ROS_INFO("Data recieve ! %f,%f,%f,%f", inputNumber_X, inputNumber_Y, inputNumber_Z, inputNumber_YAW);
      ros::spinOnce();

      mymission.reset();
      mymission.setTarget(inputNumber_X, inputNumber_Y, inputNumber_Z, inputNumber_YAW);

      while (!mymission.finished || !mymission.state)
        ros::spinOnce();
      ROS_INFO("Mission successfully");
      break;
    case 'b':
      M100landing();
      break;
    case 'e':
      M100gohome();
      break;
    case 'q':
      return 0;
    case 'i':
      info_flag = !info_flag;
      ROS_INFO("+-+-+myx=%f, myy=%f, myz=%f", current_local_pos.x, current_local_pos.y, current_local_pos.z);
      break;
    default:
      break;
    }
    ros::spinOnce();
  }
  return 0;
}

void M100landing()
{
  if(flight_status != DJISDK::M100FlightStatus::M100_STATUS_IN_AIR)

  ROS_INFO("land");
  takeoff_land(dji_sdk::DroneTaskControl::Request::TASK_LAND);
}

bool M100gohome()
{
  ROS_INFO("go home");
  takeoff_land(dji_sdk::DroneTaskControl::Request::TASK_GOHOME);
}

// void localOffsetFromGpsOffset(geometry_msgs::Vector3 &deltaNed,
//                               sensor_msgs::NavSatFix &target,
//                               sensor_msgs::NavSatFix &origin)
// {
//   double deltaLon = target.longitude - origin.longitude;
//   double deltaLat = target.latitude - origin.latitude;

//   deltaNed.y = deltaLat * deg2rad * C_EARTH;
//   deltaNed.x = deltaLon * deg2rad * C_EARTH * cos(deg2rad * target.latitude);
//   deltaNed.z = target.altitude - origin.altitude;
// }

geometry_msgs::Vector3 toEulerAngle(geometry_msgs::Quaternion quat)
{
  geometry_msgs::Vector3 ans;

  tf::Matrix3x3 R_FLU2ENU(tf::Quaternion(quat.x, quat.y, quat.z, quat.w));
  R_FLU2ENU.getRPY(ans.x, ans.y, ans.z);
  return ans;
}

void Mission::step()
{
  static int info_counter = 0;
  static bool finished_x = false;
  static bool finished_y = false;
  static bool finished_z = false;
  static bool finished_yaw = false;

  float yawThresholdInDeg = 2;

  float xCmd, yCmd, zCmd, yawCmd;
  ros::spinOnce();
  double yawDesiredRad = deg2rad * target_yaw;
  double yawThresholdInRad = deg2rad * yawThresholdInDeg;
  double yawInRad = toEulerAngle(current_atti).z;

  if (std::abs(target_offset_x - current_local_pos.x) < 0.01)
  {
    finished_x = true;
    xCmd = 0;
  }
  else
  {
    finished_x = false;
    xCmd = pid_x.PID_realize(current_local_pos.x, target_offset_x);
  }

  if (std::abs(target_offset_y - current_local_pos.y) < 0.01)
  {
    finished_y = true;
    yCmd = 0;
  }
  else
  {
    finished_y = false;
    yCmd = pid_y.PID_realize(current_local_pos.y, target_offset_y);
  }

  if (std::abs(target_offset_z - current_local_pos.z) < 0.01)
  {
    finished_z = true;
    zCmd = 0;
  }
  else
  {
    finished_z = false;
    zCmd = pid_z.PID_realize(current_local_pos.z, target_offset_z);
  }

  if (std::abs(yawInRad - yawDesiredRad) < yawThresholdInRad)
  {
    finished_yaw = true;
    yawCmd = 0;
  }
  else
  {
    finished_yaw = false;
    yawCmd = pid_yaw.PID_realize(yawInRad, yawDesiredRad);
  }

  if (finished_x && finished_y && finished_z && finished_yaw)
  {
    finished = true;
    return;
  }

  info_counter++;
  if (info_counter > 20)
  {
    info_counter = 0;
    ROS_INFO("+-+-+myx=%f, myy=%f, myz=%f,myang=%f", current_local_pos.x, current_local_pos.y, current_local_pos.z, yawInRad);
    ROS_INFO("=====xCmd=%f, yCmd=%f, zCmd=%f, yawCmd=%f ...", xCmd, yCmd, zCmd, yawDesiredRad);
    ROS_INFO("%d,%d,%d,%d", finished_x, finished_y, finished_z, finished_yaw);
  }

  if (finished_x || finished_y || finished_z || finished_yaw)
  {
    sensor_msgs::Joy controlVelYawRate;
    uint8_t flag = (DJISDK::VERTICAL_VELOCITY |
                    DJISDK::HORIZONTAL_VELOCITY |
                    DJISDK::YAW_RATE |
                    DJISDK::HORIZONTAL_GROUND |
                    DJISDK::STABLE_ENABLE);
    controlVelYawRate.axes.push_back(xCmd);
    controlVelYawRate.axes.push_back(yCmd);
    controlVelYawRate.axes.push_back(zCmd);
    controlVelYawRate.axes.push_back(yawCmd);
    controlVelYawRate.axes.push_back(flag);
    ctrlBrakePub.publish(controlVelYawRate);
    return;
  }

  sensor_msgs::Joy controlPosYaw;
  controlPosYaw.axes.push_back(xCmd);
  controlPosYaw.axes.push_back(yCmd);
  controlPosYaw.axes.push_back(zCmd);
  controlPosYaw.axes.push_back(yawCmd);
  ctrlPosYawPub.publish(controlPosYaw);
}

bool takeoff_land(int task)
{
  dji_sdk::DroneTaskControl droneTaskControl;

  droneTaskControl.request.task = task;

  drone_task_service.call(droneTaskControl);

  if (!droneTaskControl.response.result)
  {
    ROS_ERROR("takeoff/land fail");
    return false;
  }
  return true;
}

bool obtain_control()
{
  dji_sdk::SDKControlAuthority authority;
  authority.request.control_enable = 1;
  sdk_ctrl_authority_service.call(authority);

  if (!authority.response.result)
  {
    ROS_ERROR("obtain control failed!");
    return false;
  }
  return true;
}

bool is_M100()
{
  dji_sdk::QueryDroneVersion query;
  query_version_service.call(query);

  if (query.response.version == DJISDK::DroneFirmwareVersion::M100_31)
    return true;

  return false;
}

void attitude_callback(const geometry_msgs::QuaternionStamped::ConstPtr &msg)
{
  current_atti = msg->quaternion;
}

void local_position_callback(const geometry_msgs::PointStamped::ConstPtr &msg)
{
  current_local_pos = msg->point;
  static ros::Time start_time = ros::Time::now();
  ros::Duration elapsed_time = ros::Time::now() - start_time;

  // Down sampled to 50Hz loop
  if (elapsed_time > ros::Duration(0.02))
  {
    start_time = ros::Time::now();
    switch (mymission.state)
    {
    case 0:
      break;
    case 1:
      if (!mymission.finished)
        mymission.step();
      else
        mymission.state = 0;
    }
  }
  ros::spinOnce();
}

void gps_callback(const sensor_msgs::NavSatFix::ConstPtr &msg)
{
  current_gps = *msg;
}

void flight_status_callback(const std_msgs::UInt8::ConstPtr &msg)
{
  flight_status = msg->data;
}

void display_mode_callback(const std_msgs::UInt8::ConstPtr &msg)
{
  display_mode = msg->data;
}
bool M100monitoredTakeoff()
{
  ros::Time start_time = ros::Time::now();

  float home_altitude = current_gps.altitude;
  if (!takeoff_land(dji_sdk::DroneTaskControl::Request::TASK_TAKEOFF))
    return false;

  ros::Duration(0.01).sleep();
  ros::spinOnce();

  // Step 1: If M100 is not in the air after 10 seconds, fail.
  while (ros::Time::now() - start_time < ros::Duration(10))
  {
    ros::Duration(0.01).sleep();
    ros::spinOnce();
  }

  if (flight_status != DJISDK::M100FlightStatus::M100_STATUS_IN_AIR ||
      current_gps.altitude - home_altitude < 1.0)
  {
    ROS_ERROR("Takeoff failed.");
    return false;
  }
  else
  {
    start_time = ros::Time::now();
    ROS_INFO("Successful takeoff!");
    ros::spinOnce();
  }
  return true;
}

bool set_local_position()
{
  dji_sdk::SetLocalPosRef localPosReferenceSetter;
  set_local_pos_reference.call(localPosReferenceSetter);
  return localPosReferenceSetter.response.result;
}