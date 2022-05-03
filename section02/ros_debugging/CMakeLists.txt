cmake_minimum_required(VERSION 2.8.3)
project(ros_debugging)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package(CATKIN_DEPENDS roscpp)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(gdb_hello_world src/gdb_hello_world.cpp)
target_link_libraries(gdb_hello_world ${catkin_LIBRARIES})

add_executable(logging_hello_world src/logging_hello_world.cpp)
target_link_libraries(logging_hello_world ${catkin_LIBRARIES})

add_executable(rqt_logging src/rqt_logging.cpp)
target_link_libraries(rqt_logging ${catkin_LIBRARIES})

install(TARGETS
  gdb_hello_world logging_hello_world rqt_logging
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

foreach(dir launch )
    install(DIRECTORY ${dir}/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
