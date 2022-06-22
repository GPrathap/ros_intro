# Homework2


## Deadline

**28.06.2022, 11:59pm**


## Description
The assignment is individual. 

**Please note, there will be no tolerance for cheating.**

The assignment consists of 3 parts as following:

### Part 1: Find & Fix (8 points)

You have a package called "buggy", if you tried to build this package, it will give errors. Your task is to find and fix such bugs and fix them. The bugs and errors are not only syntax errors, or missing lines, but can be mistakes in C++ codes, msg, srv, launch file, CMakeLists and package.xml. However, the logic of the code is correct.

You may use the debugging tools to find the bugs.

Your goal is to fix the errors and run ```catkin build buggy``` and returns you a successful build. Then, you need to run ```source devel/setup.bash```. 

Then, if you fixed the errors correctly, you should run ```roslaunch buggy test.launch``` and run in another terminal

```
rosservice call /turnon "flag:            
  data: True"
```
  
Then, it should print "You finished, congrats on 5 points"

**Note: You can ask for hints for this part (up to 3 hints), each hint will cost you 0.5 point (1st hint), then 1 point (2nd hint), then 1.5 points (3rd hint). The hints are fixed (All the hints provided for the students are the same)**


**Note: You may take extra points (2 extra points) if you reported the errors, solutions and reasoning in good manner in README.md**

### Part 2: Rosbag (5 points)

You have two rosbags, you need to use rviz and rqt_plot.

Download rosbags from:


* rosbag1: http://rpg.ifi.uzh.ch/datasets/uzh-fpv-newer-versions/v3/indoor_forward_7_davis_with_gt.bag
* rosbag2: https://drive.google.com/file/d/1ZD16ZmebqIZxHbkOCW_3o8yE637WP9Yf/view?usp=sharing

Note: you can check how to use ```wget```

After downloading them, you need to run the rosbag as we did during the lab.

For the first bag: (You may increase the rate of playing the rosbag)
* visualize using Rviz: 
    - /dvs/image_raw (Image)
    - /groundtruth/odometry (Odometry)

Note: Set the fixed_frame to world

Take a screenshot in the middle of the bag (After sometime from playing the bag, you will monitor something is happening in the visualization)

* plot using rqt_plot:
    - /groundtruth/odometry/pose/pose/position

Take a screenshot in the middle of the bag (After sometime from playing the bag, you will monitor something is happening in the plotting)


For the second bag: (You may increase the rate of playing the rosbag)

* visualize using Rviz: 
    - /lio_sam/mapping/cloud_registered (PointCloud2)

Notes: 
    * Set the fixed_frame to map
    * Change size of point cloud to 0.1
    * Change decay time to 100

Take a screenshot in the middle of the bag (After sometime from playing the bag, you will monitor some sort of Innopolis map)



At the end, you will have 3 screenshots, you need to put them in folder called part2 during the submission. Name them bag1_rviz, bag1_rqt, bag2_rviz

### Part 3: Debugging tools (2 points)

You need to ues rqt_plot, rqt_graph, and rqt_console

You need to debug assignmnet1 package with the following commands:


Run the launch file then:

```
rqt_plot
```
and plot "/turtle2/pose", then take a screenshot

```
rqt_graph
```
with specify "Nodes/Topics (all)" and take a screenshot

```
rqt_console
```

Check if you have any info, warning, debug message.


At the end you will have 2 screenshots, you need to put them in folder called part3 during the submission.

Note: if you did not submit the first assignment, you can write me (@hany606) to give a package to use it for this part.

As a bonus (1 point), try to use [Plot juggler](https://github.com/facontidavide/PlotJuggler) and take a screenshots from plotting the data from it.


## Bonus points



## Submission

You need to submit a single zip file that contains the following:

* For the first part, zip the package after you fix it with readme (Readme explaining the mistakes is optional for bonus points).

* For the second part, you have 3 screenshots in a folder called part2

* For the third part, you have 2 screenshots in a folder called part3

## Grading

* This homework costs 15 points
* The deadline is flexible which means that if you are late by minutes or couple of hours (i.e, till 3 hours it is ok).
* Late submission is allowed in case of problems out of control (health including physical or mental problems). So, do not worry, your health should be your number 1 priority!
* Do not worry if you had some problems, you can ask us anytime, ask your friends, it is not bad to ask for help!
* Please do not put a lot of time in the assignment (maybe 4~5 hours for the whole assignment), enjoy your time, do not feel stressed and do not wake all the night solving the assignment, please!


