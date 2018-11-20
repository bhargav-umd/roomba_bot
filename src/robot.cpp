#include "../include/robot.hpp"
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include "ros/ros.h"

void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();

    for (int i = 0; i < laser->ranges.size(); i++) {
        std::cout << laser->ranges[i] << std::endl;
        robot::lasers.push_back(laser->ranges[i]);
    }
}

bool robot::obstacle(std::vector<double> laserscans) {
    double min = 60.0;
    for (int i = 0; i < laserscans.size(); i++) {
        if (laserscans[i] < min) {
            min = laserscans[i];
        }
    }
    std::cout << "Min value is: " << min << std::endl;

    if (min < 0.5) {
        return true;
    } else {
        return false;
    }
}
