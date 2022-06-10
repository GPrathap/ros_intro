# Exercise 1: ROS launch



## Soultion:

Check this package [here](https://github.com/GPrathap/ros_intro/tree/intro/labs/exercises_solutions/lab1/exercise3)

```bash

cd ~/labs_ws/src
catkin create pkg turtlesim_launcher
cd turtlesim_launch/launch
touch run.launch
nano run.launch
cd ~/labs_ws/
catkin build && source devel/setup.bash
roslaunch turtlesim_launch run
```

