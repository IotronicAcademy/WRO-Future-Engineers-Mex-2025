# ![Logo](other/logo.jpeg) WRO-Future-Engineers-Turkey-2024


## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members).
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom).
* `video` contains the video.md file with the link to a video where the driving demonstration exists.
* `schemes` contains one or several schematic diagrams in the form of JPEG, PNG, or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains the code of control software for all components that were programmed to participate in the competition.
* `models` is for the files for models used by 3D printers, laser cutting machines, and CNC machines to produce the vehicle elements. If there is nothing to add to this location, the directory can be removed.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation on how to connect to an SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions, etc. If there is nothing to add to this location, the directory can be removed.

## Introduction

The robot in question is equipped with a series of technological components designed to optimize its obstacle detection capabilities in this WRO robotics competition. Among its main features are three ToF (Time of Flight) range sensors, a camera, an RGB line sensor, a gear-modified gear motor for increased speed, and a servomotor that controls the direction of the robot. Each of these elements plays an important role in the operation and maneuverability of the robot.

The ToF range sensors are fundamental for the robot's navigation. These sensors are strategically positioned to allow precise obstacle detection in the robot's environment. ToF sensors operate by emitting pulses of infrared light and measuring the time it takes for the light to bounce off an object and return to the sensor. This return is measured to determine the distance between the sensor and the obstacle. In the case of the robot, the three range sensors are distributed so that one is oriented forward, while the other two are positioned to the sides. This arrangement allows for broad coverage of the environment, enabling the robot to detect obstacles not only directly in front of it but also around it. This is especially useful for avoiding collisions with walls and other nearby objects.

The camera mounted on the robot has a specific purpose related to the detection of obstacle colors. This camera is equipped to identify two main colors: red and green. The ability to detect the color of the obstacle allows the robot to make more informed decisions about its behavior. For example, if the robot detects a red obstacle, it might be programmed to avoid it differently compared to a green obstacle. The camera uses image processing to identify and distinguish these colors, involving a series of algorithms that analyze the captured image to extract relevant information about the environment.

In addition to the range sensors and the camera, the robot features an RGB line sensor. This sensor is designed to detect specific colored lines on the ground, in this case, orange and blue. The primary function of the RGB line sensor is to allow the robot to follow predefined paths based on the colors detected on the ground. For instance, if the robot is programmed to follow a blue line, the RGB sensor will identify that line and adjust the robot's movement to stay on it. This type of control is essential for applications where the robot needs to follow a specific trajectory or avoid certain areas marked by colors.

Regarding traction, the robot uses a gear-modified gear motor that increases its speed, and the traction has been changed from rear to front, improving its maneuverability in certain competition maneuvers. The servomotor connected to the steering system allows for adjusting the angle of the wheels so that the robot can turn and change direction precisely.

The construction of the robot was done using a CiberPi from Makeblock, which allows us to utilize functionalities for a better structure of the robot. The compilation and method of uploading the code are done via USB-C or Bluetooth; furthermore, this program allows for a preview without uploading the code, displaying real-time programming.

---
