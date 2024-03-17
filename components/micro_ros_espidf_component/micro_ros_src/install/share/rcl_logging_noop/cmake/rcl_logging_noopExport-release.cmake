#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_logging_noop::rcl_logging_noop" for configuration "Release"
set_property(TARGET rcl_logging_noop::rcl_logging_noop APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rcl_logging_noop::rcl_logging_noop PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librcl_logging_noop.a"
  )

list(APPEND _cmake_import_check_targets rcl_logging_noop::rcl_logging_noop )
list(APPEND _cmake_import_check_files_for_rcl_logging_noop::rcl_logging_noop "${_IMPORT_PREFIX}/lib/librcl_logging_noop.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
