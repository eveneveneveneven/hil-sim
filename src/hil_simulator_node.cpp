#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <Eigen/Dense>
#include "vessel.h"
#include "simulator_prototype/GpsPos.h"

int main(int argc, char* argv[])
{

  ros::init(argc, argv, "hil_simulator_node");
  ros::start();

  ROS_INFO("Started HIL Simulator node");

  ros::NodeHandle nh;
  ros::Publisher hil_simulator_pub = nh.advertise<simulator_prototype::GpsPos>("GpsPos", 1);
  ros::Rate loop_rate(10);
  double x, y, z, dt;
  x=0; 
  y=0;
  z=0;
  dt=0.1;
  while(ros::ok()){
    simulator_prototype::GpsPos position;

    position.Latitude = x;
    position.Longitude = y;
    position.Altitude = z;
    
    x += dt;
    y -=dt;
    hil_simulator_pub.publish(position);
    ros::spinOnce();
    loop_rate.sleep();
  }
  ROS_INFO("Exiting HIL Simulator node");
  ros::shutdown();
  return 0;
}
