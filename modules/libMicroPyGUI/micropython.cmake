# Create an INTERFACE library for our C module.
add_library(libMicroPyGUI INTERFACE)


get_filename_component(MICROPY_GUI_DIR ../../../../modules/libMicroPyGUI ABSOLUTE)

#set (ROS_MICROPY_LCD_PANEL ESP32S3_8048S070C)
#set (ROS_MICROPY_LCD_PANEL ESP32S3_8048S050C)
#set (ROS_MICROPY_LCD_PANEL 8048SC050C2)
#set (ROS_MICROPY_LCD_DRIVER_DIR ${ROS_MICROPY_GUI_DIR}/lcd-display-drivers/${ROS_MICROPY_LCD_PANEL})

set (MICROPY_GUI_SRC
    ${MICROPY_GUI_DIR}/main.c
    ${MICROPY_GUI_DIR}/mpy_lv_functions.cpp
    ${MICROPY_GUI_DIR}/mpy_LvObjectMgr/mpy_LvObjectFactory.cpp
    ${MICROPY_GUI_DIR}/mpy_LvObjectMgr/mpy_LvObject.cpp

)

list(APPEND MICROPY_FROZEN_MANIFEST
    ${MICROPY_GUI_DIR}/manifest.py
)

message("FROZEN CONTENT: ${MICROPY_FROZEN_MANIFEST}")


set (MICROPY_GUI_INC  
    "."
    ${MICROPY_GUI_DIR}/mpy_LvObjectMgr
    ${MICROROS_INC_DIR}/std_msgs
    ${MICROROS_INC_DIR}/sensor_msgs
    ${MICROROS_INC_DIR}/rosidl_typesupport_introspection_c
)

# Add our source files to the lib
target_sources(libMicroPyGUI INTERFACE
    ${MICROPY_GUI_SRC}
)

# Add the current directory as an include directory.
target_include_directories(libMicroPyGUI INTERFACE
    ${MICROPY_GUI_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE libMicroPyGUI)

