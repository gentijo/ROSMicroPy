# Create an INTERFACE library for our C module.
add_library(ROS_MICROPY_WIDGETS INTERFACE)


get_filename_component(RMP_WIDGET_DIR ../../../../modules/lib_ROSMicroPyWidgets ABSOLUTE)


set (RMP_WIDGET_SRC
    ${RMP_WIDGET_DIR}/main.c
    ${RMP_WIDGET_DIR}/rosWidgetFactory.cpp
    ${RMP_WIDGET_DIR}/widgets/ros-video/ros_video_widget.cpp
    ${RMP_WIDGET_DIR}/widgets/attitude/AttitudeIndicator.cpp

)


set (RMP_WIDGET_INC  
    "."
    ${RMP_WIDGET_DIR}/widgets/ros-video

)

# Add our source files to the lib
target_sources(ROS_MICROPY_WIDGETS INTERFACE
    ${RMP_WIDGET_SRC}
)

# Add the current directory as an include directory.
target_include_directories(ROS_MICROPY_WIDGETS INTERFACE
    ${RMP_WIDGET_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE ROS_MICROPY_WIDGETS)

