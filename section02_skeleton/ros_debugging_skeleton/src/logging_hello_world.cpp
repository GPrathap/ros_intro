
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
  ROS_INFO("this is from ros info");
  ROS_INFO_STREAM("this is from ros info " << val);
  ROS_INFO_STREAM_NAMED("node1", "ROS_INFO_STREAM_NAMED" << val);
  ROS_INFO_STREAM_COND(val<0.3, "ROS_INFO_STREAM_COND");
  ROS_INFO_STREAM_COND_NAMED(val<0.3, "node1", "val<0.3,");

  // TODO use following macros to print the value of val variable 
  // ROS_INFO, ROS_INFO_STREAM, ROS_INFO_STREAM_NAMED, ROS_INFO_STREAM_COND, ROS_INFO_STREAM_COND_NAMED
  
  // TODO Create a struct with name WhetherToLog which inherits 
  // from ros::console::FilterBase where the struct takes one argument
  // , i.e., const double& val, in the constructor
  // create an inline virtual method call isEnabled() that returns true if the val is higher that zero or else false
  
   struct WhetherToLog : public ros::console::FilterBase{
    double value;
    WhetherToLog(const double& val){
      value = val;
    }
    // WhetherToLog(const double& val):value(val){};
    inline virtual bool isEnabled(){
      if(value < 0.3){
        return true;
      }else{
        return false;
      }
    }
   };
   WhetherToLog logger_filter(0.2);
   ROS_INFO_STREAM_FILTER(&logger_filter, "ROS_INFO_STREAM_FILTER");
   for (size_t i = 0; i < 10; i++)
   {
    ROS_INFO_ONCE("Message only ones");
   }
   
  // TODO Initialize the struct you created 
  // TODO use ROS_INFO_STREAM_FILTER with the filter you created 
  // TODO If you want to print once what would be the optimal  macro that can be used?
  ros::spin();
  return EXIT_SUCCESS;
}

