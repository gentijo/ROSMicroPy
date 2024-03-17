#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "shape_msgs::shape_msgs__rosidl_generator_c" for configuration "Release"
set_property(TARGET shape_msgs::shape_msgs__rosidl_generator_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(shape_msgs::shape_msgs__rosidl_generator_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libshape_msgs__rosidl_generator_c.a"
  )

list(APPEND _cmake_import_check_targets shape_msgs::shape_msgs__rosidl_generator_c )
list(APPEND _cmake_import_check_files_for_shape_msgs::shape_msgs__rosidl_generator_c "${_IMPORT_PREFIX}/lib/libshape_msgs__rosidl_generator_c.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
