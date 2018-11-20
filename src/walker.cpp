//#include <geometry_msgs/Twists.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <string>
#include "robot.hpp"
#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");

    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    robot roomba;

    ros::Publisher chatter_pub =
        n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub =
        n.subscribe("/scan", 1000, &robot::scanCallback, &roomba);

    ros::spin();
    return 0;
}
