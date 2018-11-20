![imagen](https://raw.githubusercontent.com/ctaipuj/human_robot_interaction/master/human_robot_module.png)

# Skeleton Tracking

This package is under development based on the [openni_tracker](https://github.com/ros-drivers/openni_tracker.git) package using a kinect sensor.

The main purpose of the development is to achieve interaction with an industrial robot using human skeleton tracking.

## Requirements
1. [OpenNI](https://github.com/OpenNI/OpenNI) Framework developed to use with primesense's sensors
2. [NITE](https://github.com/arnaud-ramey/NITE-Bin-Dev-Linux-v1.5.2.23) Library required for skeleton tracking
3. In your `catkin_ws/src` directory:

`git clone https://github.com/ros-drivers/openni_camera`

`git clone https://github.com/ros-drivers/openni_tracker`

Then compile your workspace. See documentation about Kinect usage [here](http://wiki.ros.org/openni_launch)

### NOTE 
If something goes wrong try also intalling [Avin2's module for Kinect] (https://github.com/avin2/SensorKinect)

***
*Created by Nicolas Barrero Nov 2018*  
**Developed at Pontificia Universidad Javeriana Nov 2018 Bogotá D.C-Colombia**  
**"Centro Tecnologico de Automatizacion Industrial" CTAI  
Perception For Industrial Robots Project**

![imagen](https://bit.ly/2qVzHyL)
