execute_process(COMMAND "/home/wsn/HKU_UAV_Project/guidancemap/build/vision_opencv/image_pipeline/camera_calibration/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/wsn/HKU_UAV_Project/guidancemap/build/vision_opencv/image_pipeline/camera_calibration/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
