
#include <ros/ros.h>
#include <ros/console.h>

#include <std_msgs/Int32.h>
#include <geometry_msgs/Vector3.h>

#include <ros_visualization_skeleton/SetSpeed.h>

int main( int argc, char **argv )
{

  ros::init( argc, argv, "joy_hagen");
  ros::NodeHandle n;
  ros::Publisher pub_temp = n.advertise<std_msgs::Int32>( "/joy_hagen/temperature", 1000);
  ros::Publisher pub_imu = n.advertise<geometry_msgs::Vector3>( "/joy_hagen/imu", 1000);
  ros::ServiceClient srv_speed = n.serviceClient<ros_visualization_skeleton::SetSpeed>( "speed" );

  std_msgs::Int32 msg_temperature;
  geometry_msgs::Vector3 msg_imu_acceleration;
  ros_visualization_skeleton::SetSpeed msg_speed;

  int i = 0;
  ros::Rate rate( 1 );
  while( ros::ok() ) {
    // TODO set temperature value, i.e., you can define it as you wish 
    // TODO set acceleration values: x, y, and z
    // TODO set desired speed 
    // TODO publish msg_temperature and msg_imu_acceleration 
    // TODO call the service srv_speed and if it get executed, print previous_speed and new_speed
    ++i;
    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}

