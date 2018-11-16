# Human Robot Interaction Module

## Overview

This repository contains different packages that allow non-conventional interaction with industrial robots.

1. Joystick Interaction
2. Myo Interaction (Under development)
3. Skeleton Interaction (Under development)

## 1. Joystick Interaction *Developed by Paul Mouraud*

This package uses the SFML library to retrieve the data from a Logitech ExTREME3DPRO Joystick. This node publishes a topic with a custom-made message with joystick's data.

### Requirements

SFML Library available at [Simple and Fast Multimedia Library](https://www.sfml-dev.org/) or:

`sudo apt-get install libsfml-dev` (recommended)

### joystick_state.msg

It is a customized message created to retrieve the joystick data and publish it through ROS. This message is generated in this package and can be used in other nodes as: 
```c++
#include <joystick_interaction/joystick_state.h>

joystick_interaction::joystick_state msg;
```
This message is composed by:
- `float32[6]` axis - return a float between -100 and 100
- `bool[12]` buttons - return True when pressed, False when released.

This message is published through the *__joystick_state__* topic by the *__joystick_data_updater__* ROS node.

#### Description of axis:
 See [joystick axis system](https://www.sfml-dev.org/documentation/2.5.0/classsf_1_1Joystick.php#a48db337092c2e263774f94de6d50baa7) for more infromation about joystick's DoF
```c++
axis[0] = X
axis[1] = Y
axis[2] = Z
axis[3] = R
axis[4] = PovX //(Point of view)
axis[5] = PovY //(Point of view)
```
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/JoystickDirections.svg/560px-JoystickDirections.svg.png" alt="alt text" width="250" height="250">

#### Description of buttons:
The button numeration corresponds to the joystick's marked number in each button.
```c++
buttons[0] = button n°1
buttons[1] = button n°2
buttons[2] = button n°3
buttons[3] = button n°4
buttons[4] = button n°5
buttons[5] = button n°6
buttons[6] = button n°7
buttons[7] = button n°8
buttons[8] = button n°9
buttons[9] = button n°10
buttons[10] = button n°11
buttons[11] = button n°12
```
### Usage

run in a terminal:

`roslaunch joystick_interaction joystick_interaction.launch`

The data will be published to `joystick_state` topic.

## 2. Myo Interaction *Developed by Paul Mouraud*

This package is under development based on the [myo_ros](https://github.com/uts-magic-lab/ros_myo.git) package using a [MYO gesture recognition armband](https://en.wikipedia.org/wiki/Myo_armband).

The main purpose of the development is to achieve interaction with an industrial robot using human body's electromiographical signals.

### Requirements
In your `catkin_ws/src` directory:

`git clone https://github.com/uts-magic-lab/ros_myo.git`

Then compile your workspace.

## 3. Skeleton Tracking

This package is under development based on the [openni_tracker](https://github.com/ros-drivers/openni_tracker.git) package using a kinect sensor.

The main purpose of the development is to achieve interaction with an industrial robot using human skeleton tracking.

### Requirements ACA VOY
- OpenNI 
- NITE

In your `catkin_ws/src` directory:

`git clone https://github.com/ros-drivers/openni_tracker.git`

Then compile your workspace.

***
*Created by Nicolas Barrero Nov 2018*

**Developed at Pontificia Universidad Javeriana Nov 2018 Bogotá D.C-Colombia**

**"Centro Tecnologico de Automatizacion Industrial" CTAI
Perception For Industrial Robots Project**
