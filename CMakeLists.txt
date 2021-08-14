# cmake requeriment
cmake_minimum_required(VERSION 3.10)



# project info
project(fast-log-system
		VERSION 0.11
		DESCRIPTION "fast log system")
set(PROJECT_VERSION_MAJOR   0)
set(PROJECT_VERSION_MINOR   1)

set(PROJECT_HOME_DIR	    ${CMAKE_HOME_DIRECTORY})
set(PROJECT_SOURCE_DIR	    ${CMAKE_HOME_DIRECTORY}/src)
set(PROJECT_HEADER_DIR	    ${CMAKE_HOME_DIRECTORY}/include)
set(PROJECT_BINARY_DIR	    ${CMAKE_HOME_DIRECTORY}/build)
set(LIBRARY_OUTPUT_PATH	    ${CMAKE_HOME_DIRECTORY}/build/lib)



# compiling parameter
# --> compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# --> gdb debug
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")



# source files
set(SOURCES     ${PROJECT_SOURCE_DIR}/flsinfo.cc
                ${PROJECT_SOURCE_DIR}/fls.cc)



# third-party libs
include(${PROJECT_HOME_DIR}/cmake/third-party.cmake)



# unit test
include(${PROJECT_HOME_DIR}/cmake/unit-test.cmake)



# libraries
add_library(fls STATIC ${SOURCES})
target_include_directories(fls PRIVATE ${PROJECT_HEADER_DIR})
