#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rclc_lifecycle::rclc_lifecycle" for configuration "Release"
set_property(TARGET rclc_lifecycle::rclc_lifecycle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rclc_lifecycle::rclc_lifecycle PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librclc_lifecycle.a"
  )

list(APPEND _cmake_import_check_targets rclc_lifecycle::rclc_lifecycle )
list(APPEND _cmake_import_check_files_for_rclc_lifecycle::rclc_lifecycle "${_IMPORT_PREFIX}/lib/librclc_lifecycle.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
