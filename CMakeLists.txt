cmake_minimum_required(VERSION 2.8.3)
project(roomba_bot)

#find catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
  geometry_msgs
)
#declare catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(walker src/walker.cpp
                      src/robot.cpp)

add_executable(teleop src/teleop.cpp)                 
target_link_libraries(walker ${catkin_LIBRARIES})

target_link_libraries(teleop ${catkin_LIBRARIES})


