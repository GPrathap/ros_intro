
#include <ros/ros.h>
#include <ros/console.h>

#include <std_msgs/Int32.h>
#include <geometry_msgs/Vector3.h>

#include <ros_visualization/SetSpeed.h>

int main( int argc, char **argv )
{

  ros::init( argc, argv, "joy_hagen");
  ros::NodeHandle n;
  ros::Publisher pub_temp = n.advertise<std_msgs::Int32>( "/joy_hagen/temperature", 1000);
  ros::Publisher pub_imu = n.advertise<geometry_msgs::Vector3>( "/joy_hagen/imu", 1000);
  ros::ServiceClient srv_speed = n.serviceClient<ros_visualization::SetSpeed>( "speed" );

  std_msgs::Int32 msg_temperature;
  geometry_msgs::Vector3 msg_imu_acceleration;
  ros_visualization::SetSpeed msg_speed;

  int i = 0;
  ros::Rate rate( 1 );
  while( ros::ok() ) {
    msg_temperature.data = i;
    msg_imu_acceleration.x = 0.1 * i;
    msg_imu_acceleration.y = 0.2 * i;
    msg_imu_acceleration.z = 0.3 * i;
    msg_speed.request.desired_speed = 0.01 * i;
    pub_temp.publish( msg_temperature );
    pub_imu.publish( msg_imu_acceleration );
    if( srv_speed.call( msg_speed ) )
    {
      ROS_INFO_STREAM(
        "SetSpeed response:\n" <<
        "previous speed = " << msg_speed.response.previous_speed << "\n" <<
        "new      speed = " << msg_speed.response.new_speed      << "\n" <<
        "motor stalled  = " << ( msg_speed.response.stalled ? "true" : "false" )
      );
    }
    else
    {
      ROS_ERROR_STREAM( "Call to speed service failed!" );
    }
    ++i;
    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}

