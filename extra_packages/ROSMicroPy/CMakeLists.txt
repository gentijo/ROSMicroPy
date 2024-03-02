message("Begining of ROSMicroPy CMake")
message ("CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("Micropython Dir: ${MICROPY_DIR}")
message ("ROS MicroPy Dir: ${ROS_MICROPY_DIR}")
message ("MicroPy Board Dir: ${MICROPY_BOARD_DIR}")
message ("MicroPy Arch Dir: ${MICROPY_ARCH_DIR}")
set(MICROPY_ARCH esp32)
get_filename_component(MICROPY_DIR  ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
get_filename_component(MICROPY_ARCH_DIR ${MICROPY_DIR}/ports/${MICROPY_ARCH} ABSOLUTE)

get_filename_component(_ROS_MICROPY_DIR  ${PROJECT_DIR}/../../extra_packages/ROSMicroPy ABSOLUTE)
set (ROS_MICROPY_DIR ${_ROS_MICROPY_DIR})

get_filename_component(_MICROROS_INC_DIR ${PROJECT_DIR}/../../extra_packages/libmicroros/include ABSOLUTE)
set (MICROROS_INC_DIR ${_MICROROS_INC_DIR} )

get_filename_component(_MICROPY_UROS_MODULE_DIR ${ROS_MICROPY_DIR}/mp_uros_modules ABSOLUTE)
set (MICROPY_UROS_MODULE_DIR ${_MICROPY_UROS_MODULE_DIR} )

get_filename_component(_MICROPY_UROS_TYPE_SUPPORT_DIR ${ROS_MICROPY_DIR}/mp_uros_type_support ABSOLUTE)
set (MICROPY_UROS_TYPE_SUPPORT_DIR ${_MICROPY_UROS_TYPE_SUPPORT_DIR} )

# Set the board if it's not already set.
if(NOT MICROPY_BOARD)
    set(MICROPY_BOARD ESP32_GENERIC)
endif()

# Set the board directory and check that it exists.
if(NOT MICROPY_BOARD_DIR)
    set(MICROPY_BOARD_DIR ${MICROPY_ARCH_DIR}/boards/${MICROPY_BOARD})
endif()

message ("\r\nProject Dir: ${PROJECT_DIR}")
message ("CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("Micropython Dir: ${MICROPY_DIR}")
message ("ROS MicroPy Dir: ${ROS_MICROPY_DIR}")
message ("MicroPy Board Dir: ${MICROPY_BOARD_DIR}")
message ("MicroPy Arch Dir: ${MICROPY_ARCH_DIR}")


if(NOT EXISTS ${MICROPY_BOARD_DIR}/mpconfigboard.cmake)
    message(FATAL_ERROR "Invalid MICROPY_BOARD specified: ${MICROPY_BOARD}")
endif()

# Define the output sdkconfig so it goes in the build directory.
#set(SDKCONFIG ${CMAKE_BINARY_DIR}/sdkconfig)

# Save the manifest file set from the cmake command line.
set(MICROPY_USER_FROZEN_MANIFEST ${MICROPY_FROZEN_MANIFEST})

# Include board config; this is expected to set (among other options):
# - SDKCONFIG_DEFAULTS
# - IDF_TARGET
include(${MICROPY_BOARD_DIR}/mpconfigboard.cmake)

# Set the frozen manifest file. Note if MICROPY_FROZEN_MANIFEST is set from the cmake
# command line, then it will override the default and any manifest set by the board.
if (MICROPY_USER_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_USER_FROZEN_MANIFEST})
elseif (NOT MICROPY_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_ARCH_DIR}/boards/manifest.py)
endif()

include(${ROS_MICROPY_DIR}/main_${IDF_TARGET}/CMakeLists.txt)
include(${ROS_MICROPY_DIR}/esp32_common.cmake)

# Define the project.
#project(micropython)

