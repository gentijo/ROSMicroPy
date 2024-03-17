# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_test_tracetools_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED test_tracetools_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(test_tracetools_FOUND FALSE)
  elseif(NOT test_tracetools_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(test_tracetools_FOUND FALSE)
  endif()
  return()
endif()
set(_test_tracetools_CONFIG_INCLUDED TRUE)

# output package information
if(NOT test_tracetools_FIND_QUIETLY)
  message(STATUS "Found test_tracetools: 4.1.1 (${test_tracetools_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'test_tracetools' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${test_tracetools_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(test_tracetools_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${test_tracetools_DIR}/${_extra}")
endforeach()
