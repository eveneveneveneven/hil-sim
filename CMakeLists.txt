cmake_minimum_required(VERSION 2.8.3)
set(PROJECT_NAME simulator_prototype)
project(${PROJECT_NAME})


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  genmsg
  message_generation
)

add_definitions(-std=c++11 -Wall -g)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_message_files(DIRECTORY msg FILES GpsPos.msg)



## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
CATKIN_DEPENDS message_runtime std_msgs
)


###########
## Build ##
###########

include_directories(  
	include/${PROJECT_NAME}
  	${catkin_INCLUDE_DIRS}
  	${GTEST_INCLUDE_DIRS}
)

add_executable(hil_simulator_node src/hil_simulator_node.cpp)
target_link_libraries(hil_simulator_node ${catkin_LIBRARIES})
add_dependencies(hil_simulator_node simulator_prototype_gen_messages_cpp)

#############
## Testing ##
#############


if(CATKIN_ENABLE_TESTING)
		##find_package(rostest REQUIRED)
		catkin_add_gtest(${PROJECT_NAME}-test launch/gtest.test src/unittest.cpp)
  	target_link_libraries(${PROJECT_NAME}-test ${catkin_LIBRARIES})
endif()