# Install script for directory: /home/wsn/HKU_UAV_Project/catkin_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/wsn/HKU_UAV_Project/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE PROGRAM FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE PROGRAM FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE FILE FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/setup.bash")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE FILE FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/setup.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE FILE FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/setup.zsh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/wsn/HKU_UAV_Project/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/wsn/HKU_UAV_Project/catkin_ws/install" TYPE FILE FILES "/home/wsn/HKU_UAV_Project/catkin_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/gtest/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/geometry2/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/geometry_experimental/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/gps_umd/gps_umd/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/image_common/image_common/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/image_pipeline/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/navigation/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/octomap_mapping/octomap_mapping/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/opencv_tests/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/perception_pcl/perception_pcl/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation_msgs/move_base_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/octomap_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_geometry/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation_msgs/map_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/pcl_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_bullet/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_eigen/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/vision_opencv/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/image_common/camera_calibration_parsers/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/Guidance-SDK-ROS/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/pcl_conversions/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/camera_calibration/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/cv_bridge/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/m100_model/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/map_server/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/gps_umd/gps_common/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/image_common/image_transport/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/image_common/camera_info_manager/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/openni_camera/openni_description/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/openni_camera/openni_launch/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/image_common/polled_camera/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_py/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/depthimage_to_laserscan/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/Onboard-SDK-ROS/dji_sdk/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/Onboard-SDK-ROS/dji_sdk_demo/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/image_publisher/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/image_view/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/image_proc/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/openni_camera/openni_camera/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/stereo_image_proc/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_ros/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/depth_image_proc/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/amcl/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/octomap_ros/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/perception_pcl/pcl_ros/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/octomap_mapping/octomap_server/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/pcl_user/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/robot_pose_ekf/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_geometry_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/fake_localization/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/vision_opencv/image_pipeline/image_rotate/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_kdl/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/test_tf2/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_sensor_msgs/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/geometry2/tf2_tools/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/Onboard-SDK-ROS/uav_test/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/voxel_grid/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/costmap_2d/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/nav_core/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/base_local_planner/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/carrot_planner/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/clear_costmap_recovery/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/dwa_local_planner/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/move_slow_and_clear/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/navfn/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/global_planner/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/rotate_recovery/cmake_install.cmake")
  include("/home/wsn/HKU_UAV_Project/catkin_ws/build/navigation/move_base/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/wsn/HKU_UAV_Project/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
