# URSim Development Setup

The `programs` folder is what URSim currently reads to load scripts and custom programs.

Currently developing using the official Docker image:  
👉 [universalrobots/ursim_e-series](https://hub.docker.com/r/universalrobots/ursim_e-series)

---

## Table of Contents
- [URSim Development Setup](#ursim-development-setup)
  - [Table of Contents](#table-of-contents)
  - [Pull the Image](#pull-the-image)
  - [Run the Image](#run-the-image)
  - [Viewing Installation (.install) Files](#viewing-installation-install-files)
- [Specifics and how to read the code](#specifics-and-how-to-read-the-code)

---

## Pull the Image
```bash
docker pull universalrobots/ursim_e-series
```

## Run the Image
Then run image with 
```bash 
docker run --rm -it universalrobots/ursim_e-series 
```

Current development is done using a vcn interface on web broswer with the following

```bash
docker run --rm -it -p 5900:5900 -p 6080:6080 universalrobots/ursim_e-series
```

-p 5900:5900 will publish the VNC port to the host, allowing the host to view the robots user interface with a VNC application, by connecting to localhost:5900.

-p 6080:6080 allows the host to view the robots user interface through a web browser with URL http://localhost:6080/vnc.html?host=localhost&port=6080⁠

To add pathing of the scripts that are in this repo, add to your command the pathing based on where it's stored. this default to /home/programs (linux distros only, adjust for yourself)
```bash
-v "~/conf/programs:/ursim/programs" universalrobots/ursim_e-series
```


Which means, run 
```bash
docker run --rm -it -p 5900:5900 -p 6080:6080 -v "REPOPATH/programs:/ursim/programs" universalrobots/ursim_e-series
```
Then access on
```bash
http://localhost:6080/vnc.html?host=localhost&port=6080⁠    
```


## Viewing Installation (.install) Files

.install files can't be opened normally through an IDE such as notepad or vscode, they have to first be converted into a zip/rar and then extracted.

# Specifics and how to read the code
There are a few different functions used on how the movement is implemented, namely:

- movej: used to reach a specific pose by reaching specific joint positions.
Position of joints (pose or q, since the kinematics are done in the background) is defined as an array of the following:
The trajectory is usually curved (not a straight line).
```bash
pose = [ q0, q1, q2, q3, q4, q5 ] 
```
q0 → Base joint (shoulder pan)

q1 → Shoulder joint (shoulder lift)

q2 → Elbow joint

q3 → Wrist 1 joint

q4 → Wrist 2 joint

q5 → Wrist 3 joint


thus, the base position as by default is as follows:

```bash
home_joint_positions = [-1.57, -1.57, 1.57, -1.57, -1.57, 0]
```

Use case: moving between waypoints where the exact path isn’t critical. For this gripper project that means not currently holding anything, and/or resetting to home / pickup position.


- moveL(pose, …)

Also interprets the target as a pose (same structure, but different meanings!).

```bash
pose = [x,y,z,Rx,Ry,Rz]
```
x, y, z ->  Cartesian position of the arm in meters (relative to the base frame) a/k/a where the arm is

Rx, Ry, Rz -> Orientation of the TCP, represented as a rotation vector. a/k/a/ what's the rotation compared to the base frame.


- get_actual_tcp_pose()
  Returns the current measured tool pose in cartesian position (not JOINTS position!)

- pose_add()
  Both arguments contain three position parameters (x, y, z) jointly called P, and three rotation
  parameters (R_x, R_y, R_z) jointly called R.