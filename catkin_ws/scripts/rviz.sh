sleep 3
source ~/HKU_UAV_Project/catkin_ws/devel/setup.bash
rosrun uav_test demo&
rosrun pcl_user pcl_saved&
roslaunch octomap_server octomap_mapping.launch&
roslaunch guidance guidance_mapping.launch&
roslaunch gps_common gps_conv_utm_odo.launch&
roslaunch robot_pose_ekf robot_pose_ekf.launch&
roslaunch m100_model display.launch&
rosrun rviz rviz&
rqt_graph