# Exercise 1: ROS workspace creation


## Solution:

```bash
# * Go to the home directory for your user
cd ~/
# * Create a directory called labs_ws and inside it a folder called src
mkdir -p labs_ws/src
# * Go inside this directory
cd labs_ws
# * Initiate the catkin workspace
mkdir build devel install logs
catkin init
# * Go inside labs_ws/src
cd src
# * Create new package called lab0 without dependencies
catkin create pkg lab0

# * Build the catkin workspace
cd ..
catkin build
source devel/setup.bash
```