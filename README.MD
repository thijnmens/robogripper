# 🤖 RoboGripper

RoboGripper is a robotic gripper system designed and built using **SolidWorks** for CAD design, **Arduino** for control, and integrated with a **URE robotic arm** platform. The project's purpose is to solve the Robot Gripper challenge of the Fontys AR course.

## Table of Contents
- [🤖 RoboGripper](#-robogripper)
  - [Table of Contents](#table-of-contents)
  - [🚀 Features](#-features)
  - [🛠️ Tech Stack](#️-tech-stack)
  - [⚙️ Setup \& Installation](#️-setup--installation)
    - [1. Hardware Assembly](#1-hardware-assembly)
    - [2. Software Setup](#2-software-setup)
  - [📸 Demo](#-demo)
  - [📜 License](#-license)


---

## 🚀 Features
- Custom-designed gripper modeled in **SolidWorks**
- Controlled via **Arduino microcontroller**, developed in C#
- The gripper is attached to a **URE robotic arm** programmed to pick up two (or more!) objects
- Design was born as a bottles gripper, but can be used to grab other types of  (small) objects.

---

## 🛠️ Tech Stack
- **Hardware**: URE robotic arm, Arduino servo motors
- **Software**: 
  - [SolidWorks](https://www.solidworks.com/) (CAD modeling)
  - [Arduino IDE](https://www.arduino.cc/en/software) (firmware programming)
  - [URScript] (https://s3-eu-west-1.amazonaws.com/ur-support-site/115824/scriptManual_SW5.11.pdf) (Universal Robots scripting language)

---

## ⚙️ Setup & Installation

### 1. Hardware Assembly
1. 3D print the gripper parts from the **SolidWorks CAD models**.  
2. Attach the gripper to the **URE robotic arm** end effector mount.  
3. Wire the servo motors and **Ardiuno** to the given PCB base, which is already connected to the UR robot.
4. Load the program on arm's software through USB or other methods.

### 2. Software Setup
1. Install whatever flashing tool you prefer.
2. Clone this repository:  
   ```bash
   git clone https://github.com/thijnmens/robogripper.git
   cd robogripper
   cd firmware
3. Select your board and port, and flash onto the microcontroller using whatever tool at your disposal.

---

## 🎮 Usage

* The gripper cannot be called externally, the process is entirely automated.
* The URE robot has a few preset position for pickup and drop, as shown in image.
* As per request, the RED tape is to be considering a no-go zone, which limits the possible pick up and especially drop points. 
  The order of said pickup points matters due to physical restrictions of the UR arm.
  ![image](docs/working-plane.jpg)

---

## 📂 Repository Structure

```
robogripper/
│── cad/            # SolidWorks models & assemblies
│── firmware/       # Arduino code & sketches
  |── README.md     # Firmware overview
|── conf            # UR configuration
  |── README.md     # Conf overview
│── docs/           # Documentation & schematics
│── README.md       # Project overview
     
```

---

## 📸 Demo




---


## 📜 License

This project is licensed under the **MIT License** – see the [LICENSE](LICENSE) file for details.

---
