cmake_minimum_required(VERSION 2.8.3)
project(ros_visualization)

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

add_service_files(FILES SetSpeed.srv)
generate_messages(DEPENDENCIES std_msgs)

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

add_executable(joy_hagen_sub src/joy_hagen_sub.cpp)
add_dependencies(joy_hagen_sub ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(joy_hagen_sub ${catkin_LIBRARIES})

add_executable(joy_hagen_pub src/joy_hagen_pub.cpp)
add_dependencies(joy_hagen_pub ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(joy_hagen_pub ${catkin_LIBRARIES})

add_executable(joy_hagen_point_cloud src/joy_hagen_point_cloud.cpp)
target_link_libraries(joy_hagen_point_cloud ${catkin_LIBRARIES} ${PCL_LIBRARIES})

add_executable(joy_hagen_camera src/joy_hagen_camera.cpp)
target_link_libraries(joy_hagen_camera ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(joy_hagen_marker_array src/joy_hagen_marker_array.cpp)
target_link_libraries(joy_hagen_marker_array ${catkin_LIBRARIES})

add_executable(joy_hagen_basic_control src/joy_hagen_basic_control.cpp)
target_link_libraries(joy_hagen_basic_control ${catkin_LIBRARIES})

install(TARGETS joy_hagen_marker_array joy_hagen_basic_control joy_hagen_sub joy_hagen_pub joy_hagen_camera joy_hagen_point_cloud 
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

foreach(dir bag config launch output)
    install(DIRECTORY ${dir}/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
