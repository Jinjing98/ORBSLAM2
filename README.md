# ORBSLAM2

This is the repo based on the work of Raul Mur-Artal, Juan D. Tardos, J. M. M. Montiel and Dorian Galvez-Lopez.
https://github.com/raulmur/ORB_SLAM2

1. I added ros image publisher nodes for Mono, Stero and RGBD, ran the system under ROS and tested it with TUM datasets.

2. I used the usb camera on my own PC to test how the ORBSLAM2 sys works.( I used the chess board to do the calibration work to get the camera intrinsics for my monocular camera ) 

3. I edited some source file so that it can publish the ID and pixel positions of good ORB features points (points contributing to the map constrution)

4. Currently I am going through the souce code of ORBSLAM2 , and expect to have a better understanding of real SLAM system.
