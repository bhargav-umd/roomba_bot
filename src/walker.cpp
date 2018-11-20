//#include <geometry_msgs/Twists.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <string>
#include "../include/robot.hpp"
#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");

    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    robot roomba;
    geometry_msgs::Twist velcty;
    ros::Publisher pub =
        n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub =
        n.subscribe("/scan", 100, &robot::scanCallback, &roomba);

    while (ros::ok()) {
        roomba.obstacle(roomba.lasers);

        if (!roomba.obstacle(roomba.lasers)) {
            ROS_INFO("All clear");
            velcty.linear.x = 0.2;
            velcty.angular.z = 0.0;
        }
        if (roomba.obstacle(roomba.lasers)) {
            ROS_INFO("Obstacle Detected");
            velcty.linear.x = 0.0;
            velcty.angular.z = 0.2;
        }
        pub.publish(velcty);
    }

    return 0;
}
