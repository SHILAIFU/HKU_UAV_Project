#!/bin/bash
#Program: Mapping Script Using Guidance and Octomap
#Author: GuoXiaodong 20171108
#Attention: rosbag --clock must run behind the ocotmap_server!!!
#MAIN 

source ~/HKU_UAV_Project/guidancemap/devel/setup.bash
# rosparam set use_sim_time true
roslaunch octomap_server octomap_mapping.launch&
rosrun nodelet nodelet manager __name:=nodelet_manager &
rosrun nodelet nodelet load depth_image_proc/convert_metric nodelet_manager &
rosrun nodelet nodelet load depth_image_proc/point_cloud_xyz nodelet_manager image_rect:=image &
# rosparam set use_sim_time true
./map.sh




