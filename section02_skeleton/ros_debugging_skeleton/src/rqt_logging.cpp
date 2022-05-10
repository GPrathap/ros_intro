
#include <ros/ros.h>
#include <ros/console.h>

int main( int argc, char **argv )
{

  ros::init( argc, argv, "rqt_logging" );
  ros::NodeHandle n;
  ros::Rate rate( 1 );
  while( ros::ok() ) {
    // TODO Use ROS_DEBUG_STREAM, ROS_INFO_STREAM, ROS_INFO_STREAM_NAMED, ROS_INFO_STREAM_NAMED, ROS_ERROR_STREAM
    // , ROS_INFO_STREAM_THROTTLE, ROS_WARN_STREAM, and ROS_FATAL_STREAM mactro to print some random messages and 
    // use rqt_debugging to see messages
    // Also, try to see how can you filtter out only ROS_FATAL_STREAM messages 
    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}

