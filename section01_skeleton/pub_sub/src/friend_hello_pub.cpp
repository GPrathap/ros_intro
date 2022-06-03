#include <ros/ros.h>
#include <hello_friend/friend_info.h>

int main(int argn, char** argc){
  ros::init(argn, argc, "r2d2_pose_estimator");
  ros::NodeHandle nd;
  ros::Publisher pub = nd.advertise<hello_friend::friend_info>("/r2d2_pose", 10);
  ros::Rate rate(10);
  while(ros::ok()){
    hello_friend::friend_info msg;
    msg.name = "r2d2";
    msg.id = 456;
    pub.publish(msg);
    ros::spinOnce();
    rate.sleep();
  } 
  return 0;
}