# Project name
set(project "19-FriendshipAndInheritance")

# Show message
message(STATUS "Project = ${project}")

# Mandatory Settings
cmake_minimum_required(VERSION 3.10)
project(${project})

# C++ standard version / -std=c++17
set(CMAKE_CXX_STANDARD 17)

# Set build type if not set
if(NOT CMAKE_BUILD_TYPE)
    # Install debug binaries
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable All + Extra Warnings
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# Set Optimization level = None
set(CMAKE_CXX_FLAGS "-O0")

# Keep debug information in binaries
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Generate compile_commands.json with a list of the commands used
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Tell CMake where to look for *.hpp and *.h files
include_directories(inc/)

# Add a library
add_library(library ./src/library.cpp)

# Add pre-compiled library headers
# find_path(SOME_PKG_INCLUDE_DIR include/some_file.hpp <FOLDER_WHERE_TO_SEARCH>)

# Add pre-compiled libraries
# find_library(SOME_LIB NAMES <some_lib> PATHS <FOLDER_WHERE_TO_SEARCH>)

# Add the executable main (declaration of what you want to build and how)
add_executable(main ./src/main.cpp)

# Tell the linker to bind the objects together
target_link_libraries(main library)

# Set the install directory used by install()
# set(CMAKE_INSTALL_PREFIX ../install)

# Install the program at the bin folder
# install(TARGETS main DESTINATION bin)
