# Human Robot Interaction Package 

## Overview

This repository contains different packages that allow non-conventional interaction with industrial robots.

1. Joystick Interaction
2. Skeleton Interaction (Under development)
3. Myo Interaction (Under development)

## Joystick Interaction

This package uses the SFML library to retrieve the data from a Logitech ExTREME3DPRO Joystick. This node publishes a topic with a custom-made message with joystick's data.

### Requirements

Library SFML [Simple and Fast Multimedia Library](https://www.sfml-dev.org/) or:`sudo apt-get install libsfml-dev`

### joystick_state.msg

It is a customized message created to retrieve the joystick data through ROS. This message is generated in this package and can be used in other nodes as: 
```c++
#include <joystick_interaction/joystick_state.h>

joystick_interaction::joystick_state msg;
```
This message is composed by:
- `float32[6]` axis - return a float between -100 and 100
- `bool[12]` buttons - return True when pressed, False when released.

This message is published through the *__joystick_state__* topic by the *__joystick_data_updater__* ROS node.

*Modified by Nicolas Barrero Nov 2018*

**Developed at Pontificia Universidad Javeriana Nov 2018
"Centro Tecnologico de Automatizacion Industrial" CTAI
Perception For Industrial Robots Project**
