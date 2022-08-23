# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

if(NOT DEFINED ENV{QMSD_8MS_PATH})
    get_filename_component(QMSD_8MS_PATH "${CMAKE_SOURCE_DIR}/../.." ABSOLUTE)
    set(ENV{QMSD_8MS_PATH} ${QMSD_8MS_PATH})
endif()

include($ENV{QMSD_8MS_PATH}/component.cmake)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(get-start)
