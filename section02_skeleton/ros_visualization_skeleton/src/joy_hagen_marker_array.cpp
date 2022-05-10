
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char **argv )
{
  ros::init( argc, argv, "joy_hagen_marker_array");
  ros::NodeHandle n;
  ros::Publisher pub_marker = n.advertise< visualization_msgs::Marker >( "/joy_hagen_marker_array/marker", 1000 );

  visualization_msgs::Marker msg_marker;
  // TODO set header frame id of msg_marker as the "marker_frame"
  msg_marker.ns = "shapes";
  msg_marker.id = 0;
  // TODO set msg_marker type and actions as  visualization_msgs::Marker::CUBE and visualization_msgs::Marker::ADD ,
  // respectively 

  msg_marker.pose.position.x = 0.;
  msg_marker.pose.position.y = 1.;
  msg_marker.pose.position.z = 2.;
  msg_marker.pose.orientation.x = 0.;
  msg_marker.pose.orientation.y = 0.;
  msg_marker.pose.orientation.z = 0.;
  msg_marker.pose.orientation.w = 1.;

  msg_marker.scale.x = 1.;
  msg_marker.scale.y = 1.;
  msg_marker.scale.z = 1.;

  msg_marker.color.r = 1.;
  msg_marker.color.g = 0.;
  msg_marker.color.b = 0.;
  msg_marker.color.a = 1.;

  msg_marker.lifetime = ros::Duration();
  ROS_INFO_STREAM("Initial Marker Created");
  ros::Rate rate(1);
  while( ros::ok() ) {
    // Set msg_marker header time stamp as ros::Time::now()
    msg_marker.pose.position.x += 0.01;
    msg_marker.pose.position.y += 0.02;
    msg_marker.pose.position.z += 0.03;
    pub_marker.publish( msg_marker );
    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}

