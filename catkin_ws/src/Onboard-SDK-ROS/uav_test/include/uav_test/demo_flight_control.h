#ifndef DEMO_FLIGHT_CONTROL_H
#define DEMO_FLIGHT_CONTROL_H

// ROS includes
#include <ros/ros.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <sensor_msgs/NavSatFix.h>
#include <std_msgs/UInt8.h>

// DJI SDK includes
#include <dji_sdk/DroneTaskControl.h>
#include <dji_sdk/SDKControlAuthority.h>
#include <dji_sdk/QueryDroneVersion.h>
#include <dji_sdk/SetLocalPosRef.h>

#include <tf/tf.h>
#include <sensor_msgs/Joy.h>
#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))
/*!
 * @brief a bare bone state machine to track the stage of the mission
 */
class Mission
{
public:
  int state;

  float target_offset_x;
  float target_offset_y;
  float target_offset_z;
  float target_yaw;

  bool finished;

  Mission() : target_offset_x(0.0), target_offset_y(0.0), target_offset_z(0.0),
              finished(false)
  {
  }

  void step();

  void setTarget(float x, float y, float z, float yaw)
  {
    target_offset_x = x;
    target_offset_y = y;
    target_offset_z = z;
    target_yaw = yaw;
    state = 1;
  }

  void reset()
  {
    finished = false;
  }
};

// void localOffsetFromGpsOffset(geometry_msgs::Vector3&  deltaNed,
//                          sensor_msgs::NavSatFix& target,
//                          sensor_msgs::NavSatFix& origin);

geometry_msgs::Vector3 toEulerAngle(geometry_msgs::Quaternion quat);

void display_mode_callback(const std_msgs::UInt8::ConstPtr &msg);

void flight_status_callback(const std_msgs::UInt8::ConstPtr &msg);

void gps_callback(const sensor_msgs::NavSatFix::ConstPtr &msg);

void attitude_callback(const geometry_msgs::QuaternionStamped::ConstPtr &msg);

void local_position_callback(const geometry_msgs::PointStamped::ConstPtr &msg);

bool takeoff_land(int task);

bool obtain_control();

bool is_M100();

void M100landing();

bool M100monitoredTakeoff();
bool M100gohome();

bool set_local_position();

#endif // DEMO_FLIGHT_CONTROL_H
