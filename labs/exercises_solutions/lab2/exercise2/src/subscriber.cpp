#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>
#include <turtlesim/TeleportRelative.h>

ros::ServiceClient teleport_client;

void callback(geometry_msgs::Pose2D msg){
    turtlesim::TeleportRelative srv;
    srv.request.linear = msg.x;
    srv.request.angular = msg.y;    
    teleport_client.call(srv);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/pose", 10, callback);
    teleport_client = n.serviceClient<turtlesim::TeleportRelative>("/turtle1/teleport_relative");
    ros::spin();
}