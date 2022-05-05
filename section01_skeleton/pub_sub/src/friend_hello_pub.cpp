#include <ros/ros.h>
#include <hello_friend/friend_info.h>
#include <sstream>

// http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
int main(int argc, char **argv)
{
  ros::init(argc, argv, "friend_hello_pub");
  ros::NodeHandle n;
  
  // TODO add publisher with topic /send_hello_topic
  // ros::Publisher pub = TODO;
  // TODO publsher should publish message at 10Hz 
  while (ros::ok())
  {
    // TODO create a message of friend_info
   
    // TODO set message fileds: name and it 
    
    // TODO publish the message 

    ros::spinOnce();
    // TODO sleep according to message rate
  }
  return 0;
}
