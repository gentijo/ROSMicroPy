message("RMP ESP CAM User Modules")
get_filename_component(MY_MODULE_DIR ../../../../modules ABSOLUTE)

get_filename_component(MOD_ROS_MICROPY_DIR ${MY_MODULE_DIR}/libROSMicroPy ABSOLUTE)
include (${MOD_ROS_MICROPY_DIR}/micropython.cmake)
