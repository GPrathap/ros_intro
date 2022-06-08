#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>

// Subscribe to a topic based on a service to start

bool start_flag = false;
float sim_time = 0;
float dt = 1;
bool dones[] = {false, false, false, false};

void start_callback_sub(const std_msgs::Bool::ConstPtr& msg){
    start_flag = msg->data;
}

void turtle1_traj(geometry_msgs::Twist::Ptr msg, float t){
    int step = int(t);
    msg->linear.x = 0;
    msg->linear.y = 0;
    msg->linear.z = 0;
    msg->angular.x = 0;
    msg->angular.y = 0;
    msg->angular.z = 0;

    // Easy trajectory
    if(step >= 0 && step < 10){
        msg->linear.x = 1;
    }
    else if(step >= 10 && step < 13){
        msg->linear.y = -1;
    }
    
    else if(step >= 13 && step < 18){
        msg->linear.x = -1;
    }

    else if(step >= 18 && step < 21){
        msg->linear.y = 1;
    }
    else if(step >= 21 && step < 24){
        msg->linear.x = -1.5;
        msg->linear.y = -1.5;
    }
    else{
        dones[0] = true;
    }
}


void turtle2_traj(geometry_msgs::Twist::Ptr msg, float t){
    int step = int(t);
    msg->linear.x = 3;
    msg->linear.y = 0;
    msg->linear.z = 0;
    msg->angular.x = 0;
    msg->angular.y = 0;
    msg->angular.z = 1.5;

    if(step >= 5){
        // msg->linear.x = 0;
        // msg->angular.z = 0;
        dones[1] = true;
    }
}

void turtle3_traj(geometry_msgs::Twist::Ptr msg, float t){
    int step = int(t);
    msg->linear.x = 2.5;
    msg->linear.y = 0;
    msg->linear.z = 0;
    msg->angular.x = 0;
    msg->angular.y = 0;
    msg->angular.z = -1.5;

    if(step >= 4){
        msg->linear.x = 0;
        msg->angular.z = 0;
        dones[2] = true;
    }
}

void turtle4_traj(geometry_msgs::Twist::Ptr msg, float t){
    int step = int(t);
    msg->linear.x = 2.5;
    msg->linear.y = 0;
    msg->linear.z = 0;
    msg->angular.x = 0;
    msg->angular.y = 0;
    msg->angular.z = -1.5;

    if(step >= 4){
        msg->linear.x = 0;
        msg->angular.z = 0;
        dones[3] = true;
    }
}

void publish_done(ros::Publisher *pub, int i){
    std_msgs::Bool msg;
    msg.data = dones[i];
    pub->publish(msg);
}

int main(int argc, char **argv){

    ros::init(argc, argv, "commander_node");
    ros::NodeHandle n;
    ros::Subscriber start_flag_sub = n.subscribe("/start_topic", 1, start_callback_sub);
    ros::Publisher turtle1_pub = n.advertise<geometry_msgs::Twist>("/turtle1_cmd", 10);
    ros::Publisher turtle2_pub = n.advertise<geometry_msgs::Twist>("/turtle2_cmd", 10);
    ros::Publisher turtle3_pub = n.advertise<geometry_msgs::Twist>("/turtle3_cmd", 10);
    ros::Publisher turtle4_pub = n.advertise<geometry_msgs::Twist>("/turtle4_cmd", 10);

    ros::Publisher turtles_done_pub[] = {n.advertise<std_msgs::Bool>("/turtle1_done", 10),
                                         n.advertise<std_msgs::Bool>("/turtle2_done", 10),
                                         n.advertise<std_msgs::Bool>("/turtle3_done", 10),
                                         n.advertise<std_msgs::Bool>("/turtle4_done", 10)
                                        };


    ros::Rate rate(1.0/dt);

    geometry_msgs::Twist::Ptr turtle1_cmd(new geometry_msgs::Twist);
    geometry_msgs::Twist::Ptr turtle2_cmd(new geometry_msgs::Twist);
    geometry_msgs::Twist::Ptr turtle3_cmd(new geometry_msgs::Twist);
    geometry_msgs::Twist::Ptr turtle4_cmd(new geometry_msgs::Twist);

    while(ros::ok()){
        if(start_flag){
            sim_time += dt;
            turtle1_traj(turtle1_cmd, sim_time);
            turtle2_traj(turtle2_cmd, sim_time);
            turtle3_traj(turtle3_cmd, sim_time);
            turtle4_traj(turtle4_cmd, sim_time);

            turtle1_pub.publish(*turtle1_cmd);
            turtle2_pub.publish(*turtle2_cmd);
            turtle3_pub.publish(*turtle3_cmd);
            turtle4_pub.publish(*turtle4_cmd);

        }
        for(int i = 0; i < 4; i++){
            publish_done(&turtles_done_pub[i], i);
        }
        ros::spinOnce();
        rate.sleep();

    }

    return 0;

}
