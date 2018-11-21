# Roomba Turtlebot

## Overview

* In this package, we create a walker node that makes turtlebot to behave like a Roomba robot. It will move in the environment and check if there are obstacles around. If there are no obstacles, the robot moves forward. If it detects an obstacle, it will rotate in place until it stops detecting it. The node subscribes to the laser scan data and publishes velocity commands to the velocity topic of roomba(i.e, turtlebot) robot.

## Dependencies

* ROS Kinetic
* Catkin
* roscpp package
* std_msgs package
* geometry_msgs package
* genmsg package


## How to build

* Create a catkin workspace if it was not created previously:

```
mkdir rosws
cd rosws
mkdir src
catkin_make
```
* Clone the repository and build the package:
```
cd ros_ws
cd src
git clone https://github.com/bhargav-umd/roomba_bot
cd ..
catkin_make
```

## How to run

* To run the package, just run the next two commands:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch roomba_bot roomba.launch
```

Gazebo will start with the corridor map and a turtlebot moving around, turning when it detects an obstacle or moving forward when there is no obstacle.

## Recording and inspecting bag files

To record using rosbag, we have to launch `roomba.launch` but with the argument _rosbagFlag_ as true. If called as false or not called at all, the data will not be recorded.

* To record data:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch roomba_bot roomba.launch rosbagFlag:=true
```
This will record the data in the `~/.ros` folder. To access it and see its information:

```
cd ~/.ros
rosbag info roomba_bagfile.bag
```

* If the data recording is not needed, just launch:

`roslaunch roomba_bot roomba.launch` or `roslaunch roomba_bot roomba.launch rosbagFlag:=false`

## Bag file playback

To replay,:
*(Gazebo should not be running for the replay, `roscore` has to be launched in another terminal first to play using above commands)

```
rosbag play roomba_bagfile.bag
```
The bag file inside the results folder was compressed due to size issues, to run it, follow:
(Git only accepts 100MB files)
```
cd ~/ros_ws/src/roomba_turtlebot/results
rosbag decompress -f roomba_bagfile.bag
rosbag play roomba_bagfile.bag
```

