# Exercise 3: ROS launch


## Soultion:

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

