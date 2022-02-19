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
 * @file roomba_node.cpp
 * @author Gokul Hari
 * @brief main function for the roomba obstacle avoidance project
 * @version 1.0
 * @date 02-18-2022
 * @copyright Copyright (c) 2022
 *
 */
#include <roomba/roomba.h>
#include <roomba/teleoperate.h>

int main(int argc, char** argv) {
  int mode = 2;
  ros::NodeHandle* node_handler = new ros::NodeHandle();
  ros::init(argc, argv, "roomba_node");

  if (mode ==1) Teleop teleop(node_handler);
  else if (mode ==2) MoveRoomba move(node_handler);
  
  delete node_handler; // delete from heap memory
  return 0;
}