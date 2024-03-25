![](docs/images/ROSMicroPyHeader.svg)

## ROSMicroPy, 
At its core, is an intergration of Micropython and MicroROS 
providing full access to ROS environment along native Micropython tyoe support.

ROSMicroPy has two goals.
Create a platform that allows developers to be introduced to ROS robotics with a low overhead in the learning curve

#### [Get Started](docs/LearnMore.md)
#### [Learn more about the core SDK](docs/rosmicropy-sdk/README.md)
#### [Learn more about MicroROS Typesupport](docs/rosmicropy-sdk/docs/mp_uros_dataTypeParser.md)
#### [Python Example Code](./python_example_code/README.md)

![](docs/images/RMP_CoreStack.svg)

From it's core configuration, there are other ROSMicroPy modules that can be configured to provide additional functionality. 

![](docs/images/RMP_LCD_Stack.svg)

The **LCD Controller** introduces to new modules;

***ROSMicroPy-GUI***, is a [JSON Forms](https://jsonforms.io/) renderer for LVGL that allows for a Web based GUI layout designer to produce a JSON description of a screen layout that can be saved on a ROSMicroPy device.

***ROSMiicroPy-JoyCam***, is a Bluetooth HID Central Server, that makes the inputs of a JoyCon device availaible for the ROSMicroPy environment. 

![](docs/images/RMP_Cam_Stack.svg)

***ROSMicroPy-CAM*** module allows an ESP32 Cam to publish a video stream in ROS format that can be received by another ROSMMicroPy or other ROS enabled device. As images are pulled from the Camera, they are passed to the Python layer to be sent out as a ROS message or allow it to be analyzed by an image processing library such as [YOLO](https://www.kdnuggets.com/2018/09/object-detection-image-classification-yolo.html)

[Learn More](docs/LearnMore.md)