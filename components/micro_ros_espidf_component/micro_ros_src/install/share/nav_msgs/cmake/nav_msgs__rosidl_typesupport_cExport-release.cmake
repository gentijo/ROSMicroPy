#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav_msgs::nav_msgs__rosidl_typesupport_c" for configuration "Release"
set_property(TARGET nav_msgs::nav_msgs__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nav_msgs::nav_msgs__rosidl_typesupport_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnav_msgs__rosidl_typesupport_c.a"
  )

list(APPEND _cmake_import_check_targets nav_msgs::nav_msgs__rosidl_typesupport_c )
list(APPEND _cmake_import_check_files_for_nav_msgs::nav_msgs__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/libnav_msgs__rosidl_typesupport_c.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
