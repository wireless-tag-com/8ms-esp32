cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

if (NOT DEFINED PROJECT_NAME)
	project(qmsd-demo)
endif (NOT DEFINED PROJECT_NAME)
