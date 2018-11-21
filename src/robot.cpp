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
 * @file robot.cpp
 * @brief  Robot Class definition
 * @author
 * @version 1
 * @date 2018-11-20
 */

#include "../include/robot.hpp"
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include "ros/ros.h"

/* --------------------------------------------------------------------------*/
/**
 * @brief  Reads the laserscan values from sensor_msgs
 *
 * @Param laser vector to contain all readings
 */
/* --------------------------------------------------------------------------*/
void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();
    for (int i = 0; i < laser->ranges.size(); i++) {
        // std::cout << laser->ranges[i] << std::endl;
        robot::lasers.push_back(laser->ranges[i]);
    }
}

/* --------------------------------------------------------------------------*/
/**
 * @brief  To determine if obstacle is present in range
 *
 * @Param laserscans: compares this with minimum value and decide if obstacle
 * is present or not
 *
 * @Returns  true if obstacle is closeby else falso
 */
/* --------------------------------------------------------------------------*/
bool robot::obstacle(std::vector<double> laserscans) {
    double min = 65.0;
    for (int i = 0; i < laserscans.size(); i++) {
        if (laserscans[i] < min) {
            min = laserscans[i];
        }
    }
    //    std::cout << "Min: " << min << std::endl;
    //    Check if obstacle is present nearby roomba, threshold values were
    //    found by multiple iterations
    if (min < 0.65) {
        return true;
    } else {
        return false;
    }
}
