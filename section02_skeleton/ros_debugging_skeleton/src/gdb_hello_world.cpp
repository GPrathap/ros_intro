
#include <ros/ros.h>
#include <ros/console.h>

#define OVERRIDE_NODE_VERBOSITY_LEVEL 1

int main( int argc, char **argv )
{
  ros::init( argc, argv, "gdb_hello_world" );
  #if OVERRIDE_NODE_VERBOSITY_LEVEL
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug);
  #endif
  ros::NodeHandle n;
  const double val = 3.14;
  ROS_DEBUG("Since debugging is enable, this will be logged %f", val);
  ROS_DEBUG_STREAM("Debugging can be created as a stream " << val);
  ros::spinOnce();
  return EXIT_SUCCESS;
}

