# Introduction to ROS
## Course Structure :space_invader:
    
- Section 1 :alien:	
    - ROS Fundamentals [:books:	lecture 01](lectures/ros_lecture01.pdf) [:books:	lecture 02](lectures/ros_lecture02.pdf)
    - Workout Examples :books:	
- Section 2 :alien:	
    - ROS Debugging :books:	
    - ROS Visualization :books:	
    - ROS Basic Control :books:	
    - ROS Simulation (Gazebo+URDF) :books:	
- Section 3 :alien:	
    - Mini Group Project 
- References
    - http://wiki.ros.org/Documentation
    - Learning ROS for Robotics Programming by Aaron Martinez and Enrique Fernández

## Instruction for running the docker container  

    chmod + section00/run_ros_node_[cpu|gpu].sh

### To create a docker container (name ros_intro_node)
    ./section00/run_ros_node_[cpu|gpu].sh run 
### To enter the container 
    ./section00/run_ros_node_[cpu|gpu].sh enter 
### To start the container 
    ./section00/run_ros_node_[cpu|gpu].sh start 
### To stop the container 
    ./section00/run_ros_node_[cpu|gpu].sh stop


## References :books:

**Notes: In our cousrse (Summer 2022 version):** we are using Ubuntu 20.04, ROS Noetic, and catkin package for build (i.e. we are using ```catkin build``` not ```catkin_make```, [if you are interested to know history of catkin](https://catkin-tools.readthedocs.io/en/latest/history.html)). In some of the following sources, they might use different settings


- A course from edX: [link](https://learning.edx.org/course/course-v1:DelftX+ROS1x+1T2021/home)
- ROS industrial course: [link](https://industrial-training-master.readthedocs.io/en/melodic/index.html#)
- Learning ROS for Robotics Programming by Aaron Martinez and Enrique Fernández: [link](https://github.com/fjibj/ROSplay/blob/master/Learning%20ROS%20for%20Robotics%20Programming%20-%20Second%20Edition.pdf)
- Learning ROS for Robotics Programming by Aaron Martinez and Enrique Fernández GitHub exercises: [link](https://github.com/AaronMR/Learning_ROS_for_Robotics_Programming_2nd_edition)
- ROS best practices from ETH-Zurich: [link](https://github.com/leggedrobotics/ros_best_practices/wiki), [Course link](https://rsl.ethz.ch/education-students/lectures/ros.html)
- ROS Enhancement Protocol includes the conventions and style guide: [link](https://www.ros.org/reps/rep-0000.html)
- The Missing Semester of Your CS Education from MIT: [link](https://missing.csail.mit.edu/)
- Linux commands cheat sheet: [link1](https://linuxconfig.org/linux-commands-cheat-sheet), [link2](https://www.guru99.com/linux-commands-cheat-sheet.html)
- Catkin cheat sheet: [link](https://catkin-tools.readthedocs.io/en/latest/cheat_sheet.html)
- ROS cheat sheet: [link](https://courses.edx.org/assets/courseware/v1/83b19d128b084ebf43b778f572b14932/asset-v1:DelftX+ROS1x+1T2020+type@asset+block/ROScheatsheet.pdf)
