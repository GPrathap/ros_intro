#include <ros/ros.h>
#include <buggy/CustomMsg.h>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub");
  ros::NodeHandle n;
  
  buggy::CustomMsg msg;
  
  ros::Subscriber pub = n.advertise<buggy::CustomMsg>("/topic1", 1000);
  ros::Rate rate(10);

  while(ros::ok()){
    msg.name.data = "buggy_msg";
    msg.flag.data = true;

    pub.publish(msg);

    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}

