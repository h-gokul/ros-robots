
# Rover

This `rover` folder contains the first project which was to design a toy car ROS package and perform teleoperation using publishers. Refer the Readme and  report of this project folder for further implementation details. 

Authors:  Gokul Hari; Pratik Acharya

The package name is `assembly`. The solidworks part and assembly files are available in /solidworks folder

- Paste the `/assembly` package folder in your catkin workspace.

- To launch both gazebo and Rviz use the command
$roslaunch assembly gazebo.launch$


- To operate simple publisher to actuate the robot in circles:

 $rosrun assembly simple_publisher.py$

- To teleoperate the robot

$rosrun assembly teleoperate.py$

