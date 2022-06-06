#include <ros/ros.h>
#include <stdlib.h>
#include <geometry_msgs/Pose2D.h>

int main(int argc, char **argv){

    ros::init(argc, argv, "publisher");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Pose2D>("/pose", 10);

    ros::Rate rate(1);

    while(ros::ok){
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        geometry_msgs::Pose2D pose;
        pose.x = x;
        pose.y = y;
        pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

}

