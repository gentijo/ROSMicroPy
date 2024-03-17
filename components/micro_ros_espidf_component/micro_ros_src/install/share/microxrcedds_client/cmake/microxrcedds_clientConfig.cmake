# Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(microxrcedds_client_VERSION 2.4.2)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

if((MSVC OR MSVC_IDE) AND EXISTS "${PACKAGE_PREFIX_DIR}/bin")
    set_and_check(microxrcedds_client_BIN_DIR "${PACKAGE_PREFIX_DIR}/bin")
endif()
set_and_check(microxrcedds_client_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
set_and_check(microxrcedds_client_LIB_DIR "${PACKAGE_PREFIX_DIR}/lib")
set_and_check(microxrcedds_client_DATA_DIR "${PACKAGE_PREFIX_DIR}/share")

foreach(d microcdr\;2.0.1)
    list(GET d 0 _name)
    list(GET d 1 _version)
    find_package(${_name} ${_version} EXACT REQUIRED)
endforeach()

include(${microxrcedds_client_DATA_DIR}/microxrcedds_client/cmake/microxrcedds_clientTargets.cmake)
