#include <ros/ros.h>
#include <hello_friend/friend_info_service.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client");
  if (argc != 2)
  {
    ROS_INFO("usage: need id and value");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<hello_friend::friend_info_service>("get_friend_value");
  hello_friend::friend_info_service srv;
  srv.request.value = atoi(argv[1]);
 
  if (client.call(srv))
  {
    ROS_INFO("Heartbeat %d", (int)srv.response.heartbeat);
  }
  else
  {
    ROS_ERROR("Failed to call service get_friend_value");
    return 1;
  }

  return 0;
}
