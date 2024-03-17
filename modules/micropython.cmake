
get_filename_component(MY_MODULE_DIR ../../../../modules ABSOLUTE)

get_filename_component(MOD_ROS_MICROPY_DIR ${MY_MODULE_DIR}/libROSMicroPy ABSOLUTE)
include (${MOD_ROS_MICROPY_DIR}/micropython.cmake)

get_filename_component(MOD_ROS_MICROPY_GUI_DIR ${MY_MODULE_DIR}/libROSMicroPyGUI ABSOLUTE)
include (${MOD_ROS_MICROPY_GUI_DIR}/micropython.cmake)