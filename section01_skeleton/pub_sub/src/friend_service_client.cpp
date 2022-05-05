#include <ros/ros.h>
#include <hello_friend/friend_info_service.h>
#include <cstdlib>

// http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client");
  if (argc != 2)
  {
    ROS_INFO("usage: need id and value");
    return 1;
  }

  ros::NodeHandle n;
  // TODO create a service client with the name get_friend_value
  // ros::ServiceClient client = TODO
  hello_friend::friend_info_service srv;
  // TODO set service requst value as standard user input, i.e., argv[1]
  // srv.request.value = TODO;
 
  // TODO Call the service and read the response and print the response.
  //  If the service is unavailable printer service is not available

  return 0;
}
