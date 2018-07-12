/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* 
 * Author: Chad Rockey
 */

#include <depthimage_to_laserscan/DepthImageToLaserScanROS.h>

#include <sensor_msgs/LaserScan.h>  //obstacle distance & ultrasonic
#include <sensor_msgs/CameraInfo.h> // camera info message. Contains cam params
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>

#define WIDTH 320
#define HEIGHT 240
#define IMAGE_SIZE (HEIGHT * WIDTH)

ros::Subscriber depth_image_sub;
ros::Subscriber cam_info_right_sub;
ros::Subscriber cam_info_left_sub;

ros::Publisher laserscan_pub;

sensor_msgs::ImageConstPtr depth_msg;
sensor_msgs::CameraInfoConstPtr right_info_msg;
sensor_msgs::CameraInfoPtr left_info_msg;

bool camera_online = false;

depthimage_to_laserscan::DepthImageToLaserScan dtl_;

void depth_image_callback(const sensor_msgs::ImageConstPtr &depth_img)
{
  // cv_bridge::CvImagePtr cv_ptr;
  depth_msg = depth_img;
  // try
  // {
  //   cv_ptr = cv_bridge::toCvCopy(depth_img, sensor_msgs::image_encodings::MONO16);
  // }
  // catch (cv_bridge::Exception &e)
  // {
  //   ROS_ERROR("cv_bridge exception: %s", e.what());
  //   return;
  // }
  // cv::Mat depth8(HEIGHT, WIDTH, CV_8UC1);
  // cv_ptr->image.convertTo(depth8, CV_8UC1);

  // depth_msg = depth8.toImageMsg();

  if (camera_online)
  {
    sensor_msgs::LaserScanPtr scan_msg = dtl_.convert_msg(depth_msg, right_info_msg);
    laserscan_pub.publish(scan_msg);
  }
}
void cam_info_right_callback(const sensor_msgs::CameraInfoConstPtr &cam_info)
{
  right_info_msg = cam_info;
  camera_online = true;
  // ROS_INFO("CAMERA ONLINE");
}

// void cam_info_left_callback(const sensor_msgs::CameraInfoConstPtr &cam_info){
//     left_info_msg = *cam_info;
// }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "depthimage_to_laserscan");
  ros::NodeHandle n;
  // ros::NodeHandle pnh("~");
  // depthimage_to_laserscan::DepthImageToLaserScanROS dtl(n, pnh);

  laserscan_pub = n.advertise<sensor_msgs::LaserScan>("/depthimage_to_laserscan/laserc", 1);
  depth_image_sub = n.subscribe("/guidance/depth_image", 1, &depth_image_callback);
  cam_info_right_sub = n.subscribe("/guidance/right/camera_info", 100, &cam_info_right_callback);
  // cam_info_left_sub = n.subscribe("/guidance/left/camera_info", 100, &cam_info_left_callback);

  // Set up library
  const float scan_time = 1.0 / 30.0;
  dtl_.set_scan_time(scan_time);
  const float range_min = 0.45;
  const float range_max = 10.0;
  dtl_.set_range_limits(range_min, range_max);
  const int scan_height = 1;
  dtl_.set_scan_height(scan_height);
  const std::string output_frame = "camera_depth_frame";
  dtl_.set_output_frame(output_frame);
  ROS_INFO("START SPING");

  while (ros::ok())
    ros::spinOnce();
  return 0;
}