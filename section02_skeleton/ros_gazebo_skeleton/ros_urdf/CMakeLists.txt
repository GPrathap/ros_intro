cmake_minimum_required(VERSION 2.8.3)
project(ros_urdf)

find_package(catkin REQUIRED
    COMPONENTS
      roscpp
      message_generation
      std_msgs
      geometry_msgs
      sensor_msgs
      visualization_msgs
      dynamic_reconfigure
      driver_base
      diagnostic_updater
      cv_bridge
      image_transport
      pcl_conversions
      interactive_markers)

find_package(OpenCV)
find_package(PCL REQUIRED)

catkin_package(
    CATKIN_DEPENDS
      roscpp
      message_runtime
      std_msgs
      geometry_msgs
      sensor_msgs
      visualization_msgs
      dynamic_reconfigure
      driver_base
      diagnostic_updater
      cv_bridge
      image_transport
      pcl_conversions
      interactive_markers)

include_directories(${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})

foreach(dir bag config launch output)
    install(DIRECTORY ${dir}/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
