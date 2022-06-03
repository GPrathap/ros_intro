#include "ros/ros.h"
#include <hello_friend/friend_info.h>

// http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

void callback_sub(const hello_friend::friend_info::ConstPtr& msg)
{
  // TODO use ROS_INFO or ROS_INFO_STREAM to print message content
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/sdfdsf", 1, callback_sub);
  // ros::Subscriber sub = TODO;
  ros::spin();
  return 0;
}
