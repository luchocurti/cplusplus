# Project name
set(project "exercise_2-task_2")

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
include_directories(include/)

# Add a library
# add_library(ipb_arithmetic ./src/subtract.cpp ./src/sum.cpp)

# Add pre-compiled library headers
# find_path(SOME_PKG_INCLUDE_DIR include/some_file.hpp <FOLDER_WHERE_TO_SEARCH>)

# Add pre-compiled libraries
# find_library(SOME_LIB NAMES <some_lib> PATHS <FOLDER_WHERE_TO_SEARCH>)

################################################################################
# search for clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)

# setup clang-tidy command from executable + options
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")
################################################################################

# Add the executable main (declaration of what you want to build and how)
add_executable(task_2 ./src/main.cpp)

# Tell the linker to bind the objects together
target_link_libraries(task_2)

# Set the install directory used by install()
set(CMAKE_INSTALL_PREFIX ..)

# Install the program at the bin folder
install(TARGETS task_2 DESTINATION bin)

# Options
# -------
# set_target_properties(task_2 PROPERTIES CXX_CLANG_TIDY "${CMAKE_CXX_CLANG_TIDY}")
# option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" ON)
# include(/home/luciano/cpp/exercises/exercise_2/cmake/StaticAnalyzers.cmake)    # clang-tidy

################################################################################
# set CXX_CLANG_TIDY property after defining the target
set_target_properties(task_2 PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
################################################################################

