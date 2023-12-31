message("Begining of MP CMake")

# Set location of base MicroPython directory.
if(NOT MICROPY_DIR)
    get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
endif()

get_filename_component(MICROPY_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)

get_filename_component(MICROPY_UROS_BASE_DIR ${PROJECT_DIR}/../../extra_packages/ROSMicroPy ABSOLUTE)
get_filename_component(MICROPY_UROS_MODULE_DIR ${MICROPY_UROS_BASE_DIR}/mp_uros_modules ABSOLUTE)
get_filename_component(MICROPY_UROS_TYPE_SUPPORT_DIR ${MICROPY_UROS_BASE_DIR}/mp_uros_type_support ABSOLUTE)

get_filename_component(MICROROS_INC_DIR ${PROJECT_DIR}/../../extra_packages/libmicroros/include ABSOLUTE)

message ("\r\n Project Dir: ${PROJECT_DIR}")
message ("\r\n CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("\r\n Micropython Dir: ${MICROPY_DIR}")
message ("\r\n Micropython Port Dir: ${MICROPY_PORT_DIR}")
message ("\r\n MicroROS INC Dir: ${MICROROS_INC_DIR}")
message ("\r\n MICROPY_UROS_BASE_DIR : ${MICROPY_UROS_BASE_DIR}")
message ("\r\n MICROPY_UROS_MODULE_DIR : ${MICROPY_UROS_MODULE_DIR}")
message ("\r\n MICROPY_UROS_TYPE_SUPPORT_DIR : ${MICROPY_UROS_TYPE_SUPPORT_DIR}")

# Set the board if it's not already set.
if(NOT MICROPY_BOARD)
    set(MICROPY_BOARD GENERIC)
endif()

# Set the board directory and check that it exists.
if(NOT MICROPY_BOARD_DIR)
    set(MICROPY_BOARD_DIR ${MICROPY_PORT_DIR}/boards/${MICROPY_BOARD})
endif()

message ("\r\n Micropython Board Dir: ${MICROPY_BOARD_DIR}")

if(NOT EXISTS ${MICROPY_BOARD_DIR}/mpconfigboard.cmake)
    message(FATAL_ERROR "Invalid MICROPY_BOARD specified: ${MICROPY_BOARD}")
endif()

# Save the manifest file set from the cmake command line.
set(MICROPY_USER_FROZEN_MANIFEST ${MICROPY_FROZEN_MANIFEST})


# Include board config; this is expected to set SDKCONFIG_DEFAULTS (among other options).
include(${MICROPY_BOARD_DIR}/mpconfigboard.cmake)



# Set the frozen manifest file. Note if MICROPY_FROZEN_MANIFEST is set from the cmake
# command line, then it will override the default and any manifest set by the board.
if (MICROPY_USER_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_USER_FROZEN_MANIFEST})
elseif (NOT MICROPY_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_PORT_DIR}/boards/manifest.py)
endif()

# Include core source components.
include(${MICROPY_DIR}/py/py.cmake)


if(NOT CMAKE_BUILD_EARLY_EXPANSION)
    # Enable extmod components that will be configured by extmod.cmake.
    # A board may also have enabled additional components.
    set(MICROPY_PY_BTREE ON)

    include(${MICROPY_DIR}/py/usermod.cmake)
    include(${MICROPY_DIR}/extmod/extmod.cmake)
endif()

set(MICROPY_QSTRDEFS_PORT
    ${MICROPY_PORT_DIR}/qstrdefsport.h
)

set(MICROPY_SOURCE_SHARED
    ${MICROPY_DIR}/shared/readline/readline.c
    ${MICROPY_DIR}/shared/netutils/netutils.c
    ${MICROPY_DIR}/shared/timeutils/timeutils.c
    ${MICROPY_DIR}/shared/runtime/interrupt_char.c
    ${MICROPY_DIR}/shared/runtime/stdout_helpers.c
    ${MICROPY_DIR}/shared/runtime/sys_stdio_mphal.c
    ${MICROPY_DIR}/shared/runtime/pyexec.c
)

set(MICROPY_SOURCE_LIB
    ${MICROPY_DIR}/lib/littlefs/lfs1.c
    ${MICROPY_DIR}/lib/littlefs/lfs1_util.c
    ${MICROPY_DIR}/lib/littlefs/lfs2.c
    ${MICROPY_DIR}/lib/littlefs/lfs2_util.c
    ${MICROPY_DIR}/lib/mbedtls_errors/mp_mbedtls_errors.c
    ${MICROPY_DIR}/lib/oofatfs/ff.c
    ${MICROPY_DIR}/lib/oofatfs/ffunicode.c
)
if(IDF_TARGET STREQUAL "esp32c3")
    list(APPEND MICROPY_SOURCE_LIB ${MICROPY_DIR}/shared/runtime/gchelper_generic.c)
endif()

set(MICROPY_SOURCE_DRIVERS
    ${MICROPY_DIR}/drivers/bus/softspi.c
    ${MICROPY_DIR}/drivers/dht/dht.c
)

set(MICROPY_SOURCE_PORT
    ${MICROPY_PORT_DIR}/main.c
    ${MICROPY_PORT_DIR}/uart.c
    ${MICROPY_PORT_DIR}/usb.c
    ${MICROPY_PORT_DIR}/usb_serial_jtag.c
    ${MICROPY_PORT_DIR}/gccollect.c
    ${MICROPY_PORT_DIR}/mphalport.c
    ${MICROPY_PORT_DIR}/fatfs_port.c
    ${MICROPY_PORT_DIR}/help.c
    ${MICROPY_PORT_DIR}/modutime.c
    ${MICROPY_PORT_DIR}/machine_bitstream.c
    ${MICROPY_PORT_DIR}/machine_timer.c
    ${MICROPY_PORT_DIR}/machine_pin.c
    ${MICROPY_PORT_DIR}/machine_touchpad.c
    ${MICROPY_PORT_DIR}/machine_adc.c
    ${MICROPY_PORT_DIR}/machine_adcblock.c
    ${MICROPY_PORT_DIR}/machine_dac.c
    ${MICROPY_PORT_DIR}/machine_i2c.c
    ${MICROPY_PORT_DIR}/machine_i2s.c
    ${MICROPY_PORT_DIR}/machine_uart.c
    ${MICROPY_PORT_DIR}/modmachine.c
    ${MICROPY_PORT_DIR}/network_common.c
    ${MICROPY_PORT_DIR}/network_lan.c
    ${MICROPY_PORT_DIR}/network_ppp.c
    ${MICROPY_PORT_DIR}/network_wlan.c
    ${MICROPY_PORT_DIR}/mpnimbleport.c
    ${MICROPY_PORT_DIR}/modsocket.c
    ${MICROPY_PORT_DIR}/modesp.c
    ${MICROPY_PORT_DIR}/esp32_nvs.c
    ${MICROPY_PORT_DIR}/esp32_partition.c
    ${MICROPY_PORT_DIR}/esp32_rmt.c
    ${MICROPY_PORT_DIR}/esp32_ulp.c
    ${MICROPY_PORT_DIR}/modesp32.c
    ${MICROPY_PORT_DIR}/machine_hw_spi.c
    ${MICROPY_PORT_DIR}/machine_wdt.c
    ${MICROPY_PORT_DIR}/mpthreadport.c
    ${MICROPY_PORT_DIR}/machine_rtc.c
    ${MICROPY_PORT_DIR}/machine_sdcard.c

)

set(MICROPY_UROS_MODULES
    #
    # Bind Python to ROS
    ${MICROPY_UROS_MODULE_DIR}/uros_mesg_func.c
    ${MICROPY_UROS_MODULE_DIR}/uros_base_func.c

    ${MICROPY_UROS_MODULE_DIR}/mp_uros_thread.c
    ${MICROPY_UROS_MODULE_DIR}/mp_obj_tools.c
    ${MICROPY_UROS_MODULE_DIR}/uros_mp_reg.c

    ${MICROPY_UROS_TYPE_SUPPORT_DIR}/mp_uros_type_support.c
)

set(MICROPY_UROS_TYPESUPPORT
    #
    # Bind Python to ROS
    ${MICROPY_UROS_TYPE_SUPPORT_DIR}/mp_uros_type_support.c
)

message ("MICROPY_SOURCE_PY: ${MICROPY_SOURCE_PY}")
message ("MICROPY_SOURCE_EXTMOD : ${MICROPY_SOURCE_EXTMOD}")
message ("MICROPY_SOURCE_USERMOD : ${MICROPY_SOURCE_USERMOD}")
message ("MICROPY_SOURCE_SHARED : ${MICROPY_SOURCE_SHARED}")

message ("MICROPY_SOURCE_LIB : ${MICROPY_SOURCE_LIB}")
message ("MICROPY_SOURCE_PORT : ${MICROPY_SOURCE_PORT}")
message ("MICROPY_SOURCE_BOARD : ${MICROPY_SOURCE_BOARD}")
message ("MICROPY_UROS_DIR : ${MICROPY_UROS_DIR}")

set(MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_USERMOD}
    ${MICROPY_SOURCE_SHARED}
    ${MICROPY_SOURCE_LIB}
    ${MICROPY_SOURCE_PORT}
    ${MICROPY_SOURCE_BOARD}
    ${MICROPY_UROS_MODULES}
    ${MICROPY_UROS_TYPESUPPORT}

)


list(APPEND MICROPY_CPP_INC_EXTRA  
    ${MICROROS_INC_DIR}/rcl_action
    ${MICROROS_INC_DIR}/action_msgs
    ${MICROROS_INC_DIR}/unique_identifier_msgs
    ${MICROROS_INC_DIR}/builtin_interfaces
    ${MICROROS_INC_DIR}
    ${MICROROS_INC_DIR}/rcl
    ${MICROROS_INC_DIR}/rcutils
    ${MICROROS_INC_DIR}/rmw
    ${MICROROS_INC_DIR}/rosidl_runtime_c
    ${MICROROS_INC_DIR}/rosidl_typesupport_interface
)



set(IDF_COMPONENTS
    app_update
    bootloader_support
    bt
    driver
    esp_adc_cal
    esp_common
    esp_eth
    esp_event
    esp_ringbuf
    esp_rom
    esp_wifi
    freertos
    heap
    log
    lwip
    mbedtls
    mdns
    newlib
    nvs_flash
    sdmmc
    soc
    spi_flash
    tcpip_adapter
    ulp
    vfs
    xtensa
)

if(IDF_VERSION_MINOR GREATER_EQUAL 1 OR IDF_VERSION_MAJOR GREATER_EQUAL 5)
    list(APPEND IDF_COMPONENTS esp_netif)
endif()

if(IDF_VERSION_MINOR GREATER_EQUAL 2 OR IDF_VERSION_MAJOR GREATER_EQUAL 5)
    list(APPEND IDF_COMPONENTS esp_system)
    list(APPEND IDF_COMPONENTS esp_timer)
endif()

if(IDF_VERSION_MINOR GREATER_EQUAL 3 OR IDF_VERSION_MAJOR GREATER_EQUAL 5)
    list(APPEND IDF_COMPONENTS esp_hw_support)
    list(APPEND IDF_COMPONENTS esp_pm)
    list(APPEND IDF_COMPONENTS hal)
endif()

if(IDF_TARGET STREQUAL "esp32")
    list(APPEND IDF_COMPONENTS esp32)
elseif(IDF_TARGET STREQUAL "esp32c3")
    list(APPEND IDF_COMPONENTS esp32c3)
    list(APPEND IDF_COMPONENTS riscv)
elseif(IDF_TARGET STREQUAL "esp32s2")
    list(APPEND IDF_COMPONENTS esp32s2)
    list(APPEND IDF_COMPONENTS tinyusb)
elseif(IDF_TARGET STREQUAL "esp32s3")
    list(APPEND IDF_COMPONENTS esp32s3)
    list(APPEND IDF_COMPONENTS tinyusb)
endif()

# Register the main IDF component.
idf_component_register(
    SRCS
        ${MICROPY_SOURCE_PY}
        ${MICROPY_SOURCE_EXTMOD}
        ${MICROPY_SOURCE_SHARED}
        ${MICROPY_SOURCE_LIB}
        ${MICROPY_SOURCE_DRIVERS}
        ${MICROPY_SOURCE_PORT}
        ${MICROPY_SOURCE_BOARD}
        ${MICROPY_UROS_MODULES}
        ${MICROPY_UROS_TYPESUPPORT}
    INCLUDE_DIRS
        ${MICROPY_INC_CORE}
        ${MICROPY_INC_USERMOD}
        ${MICROPY_PORT_DIR}
        ${MICROPY_BOARD_DIR}
        ${CMAKE_BINARY_DIR}
        ${MICROPY_PORT_DIR}
        ${MICROPY_UROS_MODULE_DIR}
        ${MICROPY_UROS_TYPE_SUPPORT_DIR}
        ${MICROROS_INC_DIR}
        ${PROJECT_DIR}/main
    REQUIRES
        ${IDF_COMPONENTS}
        libmicroros
)

# Set the MicroPython target as the current (main) IDF component target.
set(MICROPY_TARGET ${COMPONENT_TARGET})

# Define mpy-cross flags, for use with frozen code.
set(MICROPY_CROSS_FLAGS -march=xtensawin)

# Set compile options for this port.
target_compile_definitions(${MICROPY_TARGET} PUBLIC
    ${MICROPY_DEF_CORE}
    MICROPY_ESP_IDF_4=1
    MICROPY_VFS_FAT=1
    MICROPY_VFS_LFS2=1
    FFCONF_H=\"${MICROPY_OOFATFS_DIR}/ffconf.h\"
    LFS1_NO_MALLOC LFS1_NO_DEBUG LFS1_NO_WARN LFS1_NO_ERROR LFS1_NO_ASSERT
    LFS2_NO_MALLOC LFS2_NO_DEBUG LFS2_NO_WARN LFS2_NO_ERROR LFS2_NO_ASSERT
)

# Disable some warnings to keep the build output clean.
target_compile_options(${MICROPY_TARGET} PUBLIC
    -Wno-clobbered
    -Wno-deprecated-declarations
    -Wno-missing-field-initializers
)

# Additional include directories needed for private NimBLE headers.
target_include_directories(${MICROPY_TARGET} PUBLIC
    ${IDF_PATH}/components/bt/host/nimble/nimble
)

# Add additional extmod and usermod components.
target_link_libraries(${MICROPY_TARGET} micropy_extmod_btree)
target_link_libraries(${MICROPY_TARGET} usermod)

# Collect all of the include directories and compile definitions for the IDF components.
foreach(comp ${IDF_COMPONENTS})
    micropy_gather_target_properties(__idf_${comp})
endforeach()

if(IDF_VERSION_MINOR GREATER_EQUAL 2 OR IDF_VERSION_MAJOR GREATER_EQUAL 5)
    # These paths cannot currently be found by the IDF_COMPONENTS search loop above,
    # so add them explicitly.
    list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/soc/soc/${IDF_TARGET}/include)
    list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/soc/soc/include)
    if(IDF_VERSION_MINOR GREATER_EQUAL 3)
        list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/tinyusb/additions/include)
        list(APPEND MICROPY_CPP_INC_EXTRA ${IDF_PATH}/components/tinyusb/tinyusb/src)
    endif()
endif()

# Include the main MicroPython cmake rules.
include(${MICROPY_DIR}/py/mkrules.cmake)
