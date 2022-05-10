
#include <ros/ros.h>
#include <ros/console.h>

// http://wiki.ros.org/roscpp/Overview/Logging
// http://wiki.ros.org/rosconsole
// http://wiki.ros.org/filters

int main( int argc, char **argv )
{

  ros::init( argc, argv, "logging_hello_world" );
  ros::NodeHandle n;
  const double val = 3.14;
  // TODO use following macros to print the value of val variable 
  // ROS_INFO, ROS_INFO_STREAM, ROS_INFO_STREAM_NAMED, ROS_INFO_STREAM_COND, ROS_INFO_STREAM_COND_NAMED
  
  // TODO Create a struct with name WhetherToLog which inherits from FilterBase where the struct takes one argument, i.e., const double& val, in the constructor
  // create an inline virtual method that returns true if the val is higher that zero or else false
  
  // TODO Initialize the struct you created 
  // TODO use ROS_INFO_STREAM_FILTER with the filter you created 
  // TODO If you want to print once what would be the optimal  macro that can be used?
  ros::spinOnce();
  return EXIT_SUCCESS;
}

