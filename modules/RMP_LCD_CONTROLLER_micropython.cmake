message("RMP LCD Controller User Modules")
get_filename_component(MY_MODULE_DIR ../../../../modules ABSOLUTE)

get_filename_component(MOD_ROS_MICROPY_DIR ${MY_MODULE_DIR}/libROSMicroPy ABSOLUTE)
include (${MOD_ROS_MICROPY_DIR}/micropython.cmake)

get_filename_component(MOD_MICROPY_GUI_DIR ${MY_MODULE_DIR}/libMicroPy_JSONForms ABSOLUTE)
include (${MOD_MICROPY_GUI_DIR}/micropython.cmake)

get_filename_component(MOD_MICROPY_HELPERS_DIR ${MY_MODULE_DIR}/micropython-helpers ABSOLUTE)
include (${MOD_MICROPY_HELPERS_DIR}/micropython.cmake)

get_filename_component(MOD_ROS_MICROPY_WIDGET_DIR ${MY_MODULE_DIR}/lib_ROSMicroPyWidgets ABSOLUTE)
include (${MOD_ROS_MICROPY_WIDGET_DIR}/micropython.cmake)

#get_filename_component(MOD_MICRO_EMACS_DIR ${MY_MODULE_DIR}/lib_MicroPyEmacs ABSOLUTE)
#include (${MOD_MICRO_EMACS_DIR}/micropython.cmake)

