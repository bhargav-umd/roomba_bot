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
 * @file robot.hpp
 * @brief  Header file containing robot class and its functions
 * @author Bhargav Dandamudi
 * @version 1
 * @date 2018-11-20
 */

#pragma once
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>
#include "ros/ros.h"

/* --------------------------------------------------------------------------*/
/**
 * @brief  robot class contains two functions to read laser readings and decide
 * if there is an obstacle in front of roomba robot
 */
/* --------------------------------------------------------------------------*/
class robot {
 public:
    std::vector<double> lasers;
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);
    bool obstacle(std::vector<double> laserscans);
};
