cmake_minimum_required(VERSION 3.16)
message ("In Main CMake File")

get_filename_component(PROJECT_DIR "./" ABSOLUTE)
message("Project Dir is ${PROJECT_DIR}")  

get_filename_component(COMPONENT_DIR ${PROJECT_DIR}/../../extra_packages ABSOLUTE)
message("Component Dir is ${COMPONENT_DIR}")  

set(EXTRA_COMPONENT_DIRS 
    ${COMPONENT_DIR}/libmicroros
    ${COMPONENT_DIR}/ROSMicroPy
)

set(IDF_TARGET esp32)
# Set the board if it's not already set.
if(NOT MICROPY_BOARD)
    set(MICROPY_BOARD ESP32_GENERIC)
endif()
get_filename_component(MICROPY_DIR  ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
set (MICROPY_ARCH_DIR ${MICROPY_DIR}/ports/${IDF_TARGET} )
set (MICROPY_BOARD_DIR ${MICROPY_ARCH_DIR}/boards/${MICROPY_BOARD})



message ("\r\nMicropython CMake #1")
message ("Project Dir: ${PROJECT_DIR}")
message ("CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("Micropython Dir: ${MICROPY_DIR}")
message( "MicroPy Arch Dir: ${MICROPY_ARCH_DIR}")
message( "MicroPy Board Dir: ${MICROPY_BOARD_DIR}")

# Include board config; this is expected to set (among other options):
# - SDKCONFIG_DEFAULTS
# - IDF_TARGET
include(${MICROPY_BOARD_DIR}/mpconfigboard.cmake)

message("\r\nWrite Config File Starting..")

message("\r\n\nSDK Defaults ${SDKCONFIG_DEFAULTS}")
message("MICROPY Archdir: ${MICROPY_ARCH_DIR}")

set(SDK_CONFIG_FILE_IN          ${PROJECT_DIR}/sdkconfig)
set(SDK_CONFIG_FILE             ${PROJECT_DIR}/sdkconfig.combined)
set(SDK_CONFIG_FILE_BUILD       ${CMAKE_BINARY_DIR}/sdkconfig)

# Concatenate all sdkconfig files into a combined one for the IDF to use.
file(WRITE ${SDK_CONFIG_FILE} "")

#
# Main Project config
#
file(READ ${SDK_CONFIG_FILE_IN} CONTENTS)
file(APPEND ${SDK_CONFIG_FILE} "${CONTENTS}")

#
# Micropython Support
#
foreach(SDKCONFIG_DEFAULT ${SDKCONFIG_DEFAULTS})
    set(SDKCONFIG_DEFAULT_FULLPATH ${MICROPY_ARCH_DIR}/${SDKCONFIG_DEFAULT})
    message("SDK DEFAULT FULL: ${SDKCONFIG_DEFAULT_FULLPATH}")
    file(READ ${SDKCONFIG_DEFAULT_FULLPATH} CONTENTS)
    file(APPEND ${SDK_CONFIG_FILE} "${CONTENTS}")
endforeach()

message("\r\nSDK_CONFIG_FILE ${SDK_CONFIG_FILE}")
message("\r\nSDK_CONFIG_FILE_BUILD ${SDK_CONFIG_FILE_BUILD}")
#
# Write Output
#
configure_file(${SDK_CONFIG_FILE} ${SDK_CONFIG_FILE_BUILD} )
set(SDKCONFIG_DEFAULTS ${SDK_CONFIG_FILE_BUILD})

message("\r\nWrite Config File Complete")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(mbits-esp32s2-wrover)



