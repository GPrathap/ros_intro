
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
  ros::ServiceClient srv_speed = n.serviceClient<ros_visualization_skeleton::SetSpeed>("/speed");

  // TODO define message types 

  std_msgs::Int32 temp_data;
  geometry_msgs::Vector3 imu_data;
  ros_visualization_skeleton::SetSpeed speed_srv;
  int i = 0;
  ros::Rate rate(1);
  while( ros::ok() ) {
    // TODO set temperature value, i.e., you can define it as you wish
    temp_data.data =  i;
    imu_data.x = i*0.2;
    imu_data.y = i*0.4;
    imu_data.z = i*0.2;
    // TODO set acceleration values: x, y, and z
    // TODO set desired speed 
    // TODO publish msg_temperature and msg_imu_acceleration
    pub_temp.publish(temp_data);
    pub_imu.publish(imu_data); 
    // TODO call the service srv_speed and if it get executed, print previous_speed and new_speed
    speed_srv.request.desired_speed = 0.45*i;
    bool is_fine = srv_speed.call(speed_srv);
    if(is_fine){
      std::cout<< "service respose "<< speed_srv.response.new_speed << std::endl;
      // ROS_INFO_STREAM("service respose " << srv.response.heartbeat);
    } else {
      // std::cout<< "Something wrong with the server"<< std::endl;
      ROS_INFO("Something wrong with the server");
    }
    ++i;
    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}

