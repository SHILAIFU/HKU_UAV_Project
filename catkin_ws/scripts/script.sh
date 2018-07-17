source ../devel/setup.bash
killall roscore
# roslaunch octomap_server octomap_mapping.launch&
sleep 2
roscore&
rosrun nodelet nodelet manager __name:=nodelet_manager &
rosrun nodelet nodelet load depth_image_proc/convert_metric nodelet_manager &
rosrun nodelet nodelet load depth_image_proc/point_cloud_xyz nodelet_manager image_rect:=image &
./rviz.sh