#include "ros/ros.h"
#include <iostream>
#include <time.h> 
#include "ros_adder/random.h"

int main (int argc, char **argv){
  ros::init(argc, argv, "ros_adder_publisher");
  ros::NodeHandle nh;
  ros::Publisher adder_pub = nh.advertise<ros_adder::random>("/random_numbers",0);
  ros::Rate rate(10);
  
  srand((unsigned int)time(NULL));

  
  while (ros::ok()) {
  
  ros_adder::random num;
  
  num.num1=(float(rand())/float(rand()));
  num.num2=(float(rand())/float(rand()));
   

  
  
  ROS_INFO("First number: %f  Second number: %f  ", num.num1, num.num2);
  //ROS_INFO("Second number: %f ", num.num2);
  adder_pub.publish(num);
  rate.sleep();
  }

return 0;

}
