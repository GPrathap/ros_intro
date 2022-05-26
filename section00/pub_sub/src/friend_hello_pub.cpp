#include <ros/ros.h>
#include <hello_friend/friend_info.h>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "example1_a");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<hello_friend::friend_info>("/send_hello_topic", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    hello_friend::friend_info msg;
    std::stringstream ss;
    ss << "PubNode";
    msg.name = ss.str();
    msg.id = 345;
    //ROS_INFO("%s", msg.data.c_str());
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
