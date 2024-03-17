#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "trajectory_msgs::trajectory_msgs__rosidl_generator_c" for configuration "Release"
set_property(TARGET trajectory_msgs::trajectory_msgs__rosidl_generator_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(trajectory_msgs::trajectory_msgs__rosidl_generator_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtrajectory_msgs__rosidl_generator_c.a"
  )

list(APPEND _cmake_import_check_targets trajectory_msgs::trajectory_msgs__rosidl_generator_c )
list(APPEND _cmake_import_check_files_for_trajectory_msgs::trajectory_msgs__rosidl_generator_c "${_IMPORT_PREFIX}/lib/libtrajectory_msgs__rosidl_generator_c.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
