#include "ros/ros.h"
#include <iostream>
#include "ros_adder/random.h"
#include "ros_adder/result.h"
#include "std_msgs/Float32.h"

class ROS_SUB {

 public:
  ROS_SUB();
  void topic_cb( ros_adder::random data);
 private:
  ros::NodeHandle _nh;
  ros::Subscriber _topic_sub;
  ros::Publisher sum_pub ;
};

ROS_SUB::ROS_SUB() {
 _topic_sub= _nh.subscribe("/random_numbers", 0, &ROS_SUB::topic_cb, this);
 sum_pub=_nh.advertise<ros_adder::result>("/sum_numbers",0);
}

void ROS_SUB::topic_cb( ros_adder::random data){
 
  ros_adder::result res;
  res.num1=data.num1;
  res.num2=data.num2;
  res.sum =res.num1+res.num2;
  /*std::cout<<"First"<<num1<<std::endl;
  std::cout<<"Second"<<num2<<std::endl;
  std::cout<<"Data:"<<sum<<std::endl;*/
  
  sum_pub.publish(res);
 
}

int main(int argc, char** argv) {
  ros::init(argc,argv,"ros_subscriber");
  ROS_SUB rs;
  
 
  ros::spin();
  return 0;

}
