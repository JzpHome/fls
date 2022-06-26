# cmake requeriment
cmake_minimum_required(VERSION 3.10)



# project info
project(fast-log-system
		VERSION 0.11
		DESCRIPTION "fast log system")
set(PROJECT_VERSION_MAJOR   0)
set(PROJECT_VERSION_MINOR   1)



# compiling parameter
# --> compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# --> gdb debug
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")



# source files
set(FLS_SOURCES src/flsinfo.cc
                src/fls.cc)



# third-party libs
include(cmake/third-party.cmake)



# unit test
if(CMAKE_PROJECT_NAME STREQUAL fls)
    include(cmake/unit-test.cmake)
endif()



# libraries
add_library(fls STATIC ${FLS_SOURCES})
target_include_directories(fls PRIVATE include)
set_target_properties(fls
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
