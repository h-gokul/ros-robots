#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64
import time 

class JointController:
    def __init__(self):
        # define our publishers
        self.right_publisher = rospy.Publisher('/assembly/right_wheel_controller/command', Float64, queue_size=13) 
        self.left_publisher = rospy.Publisher('/assembly/left_wheel_controller/command', Float64, queue_size=13) 
        self.steerleft_publisher = rospy.Publisher('/assembly/left_steering_controller/command', Float64, queue_size=13) 
        self.steerright_publisher = rospy.Publisher('/assembly/right_steering_controller/command', Float64, queue_size=13) 

    def move(self, throttle = -1,steer = 0.5):
        
        rospy.init_node('publisher', anonymous=True)
        rate = rospy.Rate(10) 
        start_time = time.time()
        while not rospy.is_shutdown():
            rospy.loginfo( f"{throttle}, {steer}" )
            self.left_publisher.publish(throttle)
            self.right_publisher.publish(throttle)
            if time.time() - start_time > 25:
                self.steerleft_publisher.publish(steer)
                self.steerright_publisher.publish(steer)
                rate.sleep()

            if time.time() - start_time > 150:
                self.steerleft_publisher.publish(0)
                self.steerright_publisher.publish(0)
                self.left_publisher.publish(0)
                self.right_publisher.publish(0)

                print(" Enough playing toys")
                exit()

if __name__ == '__main__':
    try:
        controller = JointController()
        # moves for 15 secs
        controller.move(throttle = -2, steer = 1.0)

    except rospy.ROSInterruptException:
        exit()