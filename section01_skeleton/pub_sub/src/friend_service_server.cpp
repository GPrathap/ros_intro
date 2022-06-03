#include <ros/ros.h>
#include <hello_friend/friend_info_service.h>


// http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29

bool addition(hello_friend::friend_info_service::Request  &req,
         hello_friend::friend_info_service::Response &res)
{
  res.heartbeat = req.value;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle n;
  // TODO Create service and register a callback with two arguments; name the callback function as addition
  // Inside the callback, print request value and assign the response value, i.e., heartbeat, as the request value 
  ros::ServiceServer service = n.advertiseService("get_friend_value", addition);
  ROS_INFO("Service server is ready");
  ros::spin();

  return 0;
}
