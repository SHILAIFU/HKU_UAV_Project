sleep 3
source ~/HKU_UAV_Project/catkin_ws/devel/setup.bash
rosrun rviz rviz&
roslaunch guidance guidance_mapping.launch&
rqt_graph