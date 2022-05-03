#include <ros/ros.h>
#include <hello_friend/friend_info_service.h>

bool add(hello_friend::friend_info_service::Request  &req,
         hello_friend::friend_info_service::Response &res)
{
  res.heartbeat = req.value;
  ROS_INFO("request: value=%d", (int)req.value);
  ROS_INFO("response: [%d]", (int)res.heartbeat);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("get_friend_value", add);
  ROS_INFO("Service server is ready");
  ros::spin();

  return 0;
}
