/* Copyright (C)
 * 2018 - Bhargav Dandamudi
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the 'Software'), to deal in the Software without
 * restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so,subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the Software.
 *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM,OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/**
 * @file walker.cpp
 * @brief  Walker Node to run roomba robot inside the gazebo world , stop based
 *  obstacles, rotate and then continue exploring the world
 * @author Bhargav Dandamudi
 * @version 1
 * @date 2018-11-20
 */
#include <geometry_msgs/Twist.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <string>
#include "../include/robot.hpp"
#include "ros/ros.h"

/* --------------------------------------------------------------------------*/
/**
 * @brief  Main file for walker node and to publishe velocity to roomba robot
 *
 * @Param argc
 * @Param argv
 *
 * @Returns  0 if everything run with no errors
 */
/* --------------------------------------------------------------------------*/
int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");

    ros::NodeHandle n;

    robot roomba;
    geometry_msgs::Twist velcty;
    // Publisher for velocity of roomba robot
    ros::Publisher pub =
        n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
    // Subscriber for laserscan values
    ros::Subscriber sub =
        n.subscribe("/scan", 100, &robot::scanCallback, &roomba);
    ros::Rate loop_rate(10);
    while (ros::ok()) {
        // Keep moving if there are no obstacles
        if (!roomba.obstacle(roomba.lasers)) {
            ROS_INFO("All clear");
            velcty.linear.x = 0.2;
            velcty.angular.z = 0.0;
        }
        // Stop and rotate if there are obstacles in front of roomba robot
        if (roomba.obstacle(roomba.lasers)) {
            ROS_INFO("Obstacle Detected");
            velcty.linear.x = 0.0;
            velcty.angular.z = 0.2;
        }
        // Publish velocty values to roomba
        pub.publish(velcty);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
