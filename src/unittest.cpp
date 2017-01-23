#include <ros/ros.h>
#include "hil_simulator.cpp"
#include <gtest/gtest.h>
#include <thread>
#include <Eigen/Dense>


TEST(Parameters, parameterLoad){
  ros::NodeHandle testHandle;
  Vessel testVessel;
  EXPECT_FALSE(testVessel.initialize(testHandle));
}
TEST(Parameters, vectorInit){
  Vessel tempVessel;
  Eigen::Vector3d zeroMatrix = Eigen::Vector3d::Zero();
  EXPECT_EQ(getEta(tempVessel), zeroMatrix);
}

int main(int argc, char** argv){
  ros::init(argc, argv, "GTestTestNode");
  testing::InitGoogleTest(&argc, argv);

  std::thread t([]{while(ros::ok()) ros::spin();});

  auto res = RUN_ALL_TESTS();

  ros::shutdown();
  return res;
}