
#include <ros/ros.h>
#include <ros/console.h>

int main( int argc, char **argv )
{

  ros::init( argc, argv, "example2" );
  ros::NodeHandle n;
  const double val = 3.14;
  ROS_INFO( "INFO message." );
  ROS_INFO( "INFO message with argument: %f", val );
  ROS_INFO_STREAM("INFO stream message with argument: " << val);
  ROS_INFO_STREAM_NAMED("named_msg", "INFO stream message; val = " << val);
  ROS_INFO_STREAM_COND(val < 0., "Conditional INFO stream message; val (" << val << ") < 0");
  ROS_INFO_STREAM_COND(val >= 0.,
    "Conditional INFO stream message; val (" << val << ") >= 0");
  ROS_INFO_STREAM_COND_NAMED(
    val < 0., "cond_named_msg",
    "Conditional INFO stream message; val (" << val << ") < 0"
  );
  ROS_INFO_STREAM_COND_NAMED(
    val >= 0., "cond_named_msg",
    "Conditional INFO stream message; val (" << val << ") >= 0"
  );
  struct WhetherToLog : public ros::console::FilterBase {
    WhetherToLog( const double& val ) : value( val ) {}
    inline virtual bool isEnabled()
    {
      return value >= 0.;
    }
    double value;
  };
  WhetherToLog is_logging_allowed( val );
  ROS_INFO_STREAM_FILTER(&is_logging_allowed,
    "INFO stream message; val (" << val << ") >= 0"
  );
  // Once messages:
  for( int i = 0; i < 10; ++i ) {
    ROS_INFO_STREAM_ONCE("INFO stream message; i = " << i);
  }
  ros::spinOnce();
  return EXIT_SUCCESS;
}

