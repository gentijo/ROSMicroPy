# Create an INTERFACE library for our C module.
add_library(libROSMicroPyGUI INTERFACE)


get_filename_component(ROS_MICROPY_GUI_DIR ../../../../modules/libROSMicroPyGUI ABSOLUTE)

#set (ROS_MICROPY_LCD_PANEL ESP32S3_8048S070C)
#set (ROS_MICROPY_LCD_PANEL ESP32S3_8048S050C)
set (ROS_MICROPY_LCD_PANEL 8048SC050C2)

set (ROS_MICROPY_LCD_DRIVER_DIR ${ROS_MICROPY_GUI_DIR}/lcd-display-drivers/${ROS_MICROPY_LCD_PANEL})

set (ROS_MICROPY_GUI_SRC
    ${ROS_MICROPY_GUI_DIR}/main.c
    ${ROS_MICROPY_GUI_DIR}/ui/ui.c 
    ${ROS_MICROPY_GUI_DIR}/ui/ui_helpers.c 
    ${ROS_MICROPY_GUI_DIR}/widgets/ros-video/rmp_video_widget.cpp
    ${ROS_MICROPY_GUI_DIR}/widgets/rmp_widget_mgr.cpp
 

)

list(APPEND MICROPY_FROZEN_MANIFEST
    ${ROS_MICROPY_GUI_DIR}/manifest.py
)

message("FROZEN CONTENT: ${MICROPY_FROZEN_MANIFEST}")


set (ROS_MICROPY_GUI_INC  
    "."
    ${MICROROS_INC_DIR}/std_msgs
    ${MICROROS_INC_DIR}/sensor_msgs
    ${MICROROS_INC_DIR}/rosidl_typesupport_introspection_c
)

# Add our source files to the lib
target_sources(libROSMicroPyGUI INTERFACE
    ${ROS_MICROPY_GUI_SRC}
)

# Add the current directory as an include directory.
target_include_directories(libROSMicroPyGUI INTERFACE
    ${ROS_MICROPY_GUI_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE libROSMicroPyGUI)

