/**
 * MIT License
 *
 * Copyright (c) 2022 Gokul Hari
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file roomba.hpp
 * @author Gokul Hari
 * @brief A header file to declare obstacle avoidance classes
 * @version 1.0
 * @date 02-18-2022
 * @copyright Copyright (c) 2022
 *
 */

# pragma once
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/String.h>

#include <memory>
#include <sstream>
#include <string>

class MoveRoomba {
 public:
  /**
   * @brief explicit constructor for Talker object
   * @param nh pointer to nodehandle
   */
  explicit MoveRoomba(ros::NodeHandle* nh);

  /**
   * @brief Destructor for the NodeHandle
   */
  ~MoveRoomba();

  ros::NodeHandle* _nh;  // pointer of NodeHandle datatype 

public: // define the private members
  int _rate =10;  // Rate of program
  ros::Subscriber _sub_scan;  // Scan subscriber

  int _fov_degrees;             // Field of view 
  float _threshold;             // distance Threshold 
  ros::Publisher cmd_vel_publisher;  // Velocity publisher
  geometry_msgs::Twist _vel;    // Velocity twist message

  /**
   * @brief Declaring a initializer function
   */
  void __init__();

  /**
   * @brief Declaring the Main control loop of the program.
   */
  void __start__();

  /**
   * @brief Perform operations on received scan data.
   * @param msg
   */
  void scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg);

  /**
   * @brief Function to detect obstacle from scan points and take action.
   * @param scan Laser scan
   * @return geometry_msgs::Twist message to
   */
  geometry_msgs::Twist navigate(const sensor_msgs::LaserScan& scan);
};
