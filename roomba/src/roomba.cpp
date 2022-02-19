/*

 ** MIT License
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
 * @file roomba.cpp
 * @author Gokul Hari
 * @brief Definitions of functions that perform obstacle avoidance in a roomba
 * @version 1.0
 * @date 11-29-2022
 * @copyright Copyright (c) 2022
 *
 */


#include <roomba/roomba.h>

MoveRoomba::MoveRoomba(ros::NodeHandle* node_handler) {
  this->_nh = node_handler;
  __init__();
  __start__();
}

MoveRoomba::~MoveRoomba() { // use destructor to delete variables from heap 
  delete this->_nh; 
  }


void MoveRoomba::__init__() { // defininig the init function
  this->cmd_vel_publisher =
      this->_nh->advertise<geometry_msgs::Twist>("cmd_vel", this->_rate, this);
  this->_sub_scan = this->_nh->subscribe("scan", 1, &MoveRoomba::scan_callback, this);

  this->_vel.linear.x = 1;
  this->_vel.linear.y = 0;
  this->_vel.linear.z = 0;
  this->_vel.angular.x = 0;
  this->_vel.angular.y = 0;
  this->_vel.angular.z = 0;
  this->_fov_degrees = 125;
  this->_threshold = 0.5;
}

void MoveRoomba::__start__() { // defininig the start function
  ros::Rate loop_rate(this->_rate);
  while (ros::ok()) {
    ROS_DEBUG_STREAM("Roomba roams...");
    ros::spinOnce();
    loop_rate.sleep();
  }
}

void MoveRoomba::scan_callback(const sensor_msgs::LaserScan::ConstPtr& msg) {
  ROS_DEBUG_STREAM("Received scan");
  this->_vel = this->navigate(*msg);
  cmd_vel_publisher.publish(this->_vel);
}

geometry_msgs::Twist MoveRoomba::navigate(const sensor_msgs::LaserScan& lidarscan) {
  bool isobstacle = false;
  
  // check for obstacles within the field of view and given distance threshold
  for (int i = 0; i < this->_fov_degrees / 2; i++) {
    if ((lidarscan.ranges[i] <= this->_threshold) || (lidarscan.ranges[359 - i] <= _threshold)) {
      isobstacle = true;
      ROS_WARN_STREAM("[ALERT] Obstacle Detected");
      break;
    }
  }

  if (isobstacle) { // turn left if there is an obstacle 
    this->_vel.linear.x = 0; 
    this->_vel.angular.z = 0.5;   
  } 
  else { // go straight if there are no obstacles
    this->_vel.linear.x = 0.2; 
    this->_vel.angular.z = 0;
  }
  return _vel;
}
