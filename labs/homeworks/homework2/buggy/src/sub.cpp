#include <ros/ros.h>
#include <buggy/CustomMsg.h>
#include <buggy/CustomSrv.h>
#include<iostream>

bool flag  = false;
bool flag2 = false;

void callback(const buggy::CustomMsg::ConstPtr& msg)
{
	flag = msg->flag.data;
}

bool turnOn(buggy::CustomSrv::Request& req, buggy::CustomSrv::Response& res) {
  flag2 = req.flag.data;
  res.result.data = flag2;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub");
  ros::NodeHandle n;
  
  
  ros::Subscriber sub = n.subscribe("/topic", 1000, callbac);
  ros::ServiceServer turnOnService = n.Service("turnon", turnon);
  ros::Rate rate(10);

  while(ros::ok()){
    if(flag && flag2)
      std::cout << "You finished, congrats on 5 points\n";
    ros::spinOnce();
    rate.sleep();
  }  

  return 0;
}

