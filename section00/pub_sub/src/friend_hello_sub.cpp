#include "ros/ros.h"
#include <hello_friend/friend_info.h>

void callback_sub(const hello_friend::friend_info::ConstPtr& msg)
{
  ROS_INFO("Publisher name: [%s] [%i]", msg->name.c_str(), msg->id);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/send_hello_topic", 1000, callback_sub);
  ros::spin();
  return 0;
}
