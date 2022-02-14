
# Leader-Follower

This is a ROS project consisting of a leader-follower multi robot setup where the follower turtlebot detects an April Tag held by a leader robot and navigates through the environment to follow the leader. `Actionlib` package is used in for the navigation process. 

paste the package in src folder of your workspace

run the following commands in order:

- To spawn the robots
`roslaunch final_project_group3 multiplerobots.launch`
- To enable navigation settings
`roslaunch final_project_group3 navigation.launch`
- To start the leader-follower setup
`roslaunch final_project_group3 launch.launch`

Refer the report for details
