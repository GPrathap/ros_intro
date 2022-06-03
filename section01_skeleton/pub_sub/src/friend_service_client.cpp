#include <ros/ros.h>
#include <ros/console.h>
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
  ros::ServiceClient client = n.serviceClient<hello_friend::friend_info_service>("get_friend_value");
  hello_friend::friend_info_service srv;
  srv.request.value = 456;
  // TODO Call the service and read the response and print the response.
  //  If the service is unavailable printer service is not available

  bool is_fine = client.call(srv);
  if(is_fine){
    // std::cout<< "service respose "<< srv.response.heartbeat << std::endl;
    ROS_INFO_STREAM("service respose " << srv.response.heartbeat);
  } else {
    // std::cout<< "Something wrong with the server"<< std::endl;
    ROS_INFO("Something wrong with the server");
  }
  
  return 0;
}
