#include <geometry_msgs/Twists.h>
#include <string.h>
#include <sstream>
#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");

    ros::NodeHandle n;

    ros::Publisher chatter_pub =
        n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub = n.subscribe("/scan", 1000, chatterCallback);
    ros::Rate loop_rate(10);

    return 0;
}
