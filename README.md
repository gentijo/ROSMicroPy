# ROSMicroPy

ROSMicroPy is a tightly coupled intergration of MicroROS and Micropython.
## Features Include

### [SDK to control the ROS Stack](./docs/ROS_SDK.md)
+ Start / Stop ROS Stack
+ Set the Set the Address of the ROS Agent
+ Publish messages
+ Subsubscribe to messages
+ Run a server process
+ Support for all standard ROS and Custom Types
+ On device, dynanic on-the-fly, type creation

### Full Container Support
 Container definitions are include for
 + **[Running the development environment](./docs/containerDevEnv.md)**
 + **[Running the ROS Agent](./docs/containerROSAgent.md)**
 + **[Running the Teleop Key ROS Program to send commands to your device](./docs/containerTeleopKey.md)**
 + **[Running a ROS System capiable running graphical ROS apps](./docs/containerROSConsole.md)**

### How to get started 
+ **[Flash device and run on a device](./docs/DeviceSetupEasy.md)**
+ **[How to configure development environment](docs/DevEnviroment.md)**

### Thonny Support
    - Plugin to compile ROS Types and store to the device

### ROSMicro Type Support

+ **[Running the ROS Type Python generator ](./docs/typeSupport-Parser.md)**

### Micropython ROS Intergration Details
Build System
Connecting the different Threading Models
Type Support