# Obstacle Avoidance.

This is $roomba$ package is a simple obstacle avoidance implementation of a turtle bot in a gazebo simulation environment.

The robot reads the lidar scan data within it's field of view and based on a distance threshold, it determines the decision boundary to steer the course of it's navigation.  The robot has only two state of motion. When no obstacles are found, it moves straight. When an obstacle is at proximity, it moves to the left.

1) Assuming that ROS is already installed in your system and a catkin workspace is created, copy paste the package in the catkin workspace.

2) Ensure that  the following lines are added in the `.bashrc` file in the home folder

``` 
source /opt/ros/$<ROS_DISTRO>/setup.bash
source /home/$<USER_NAME>/$<ROS_DISTRO>/devel/setup.bash
export TURTLEBOT3_MODEL=waffle
```

3) To run the roomba example, run the command:

``` 
roslaunch roomba roomba.launch
```

