cmake_minimum_required(VERSION 3.0)

# Project name
project(PhonepadPuzzle)

# Create debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Ensure standard is C++11
set(CMAKE_CXX_STANDARD 11)

# Output into bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# Our source files
set(SOURCE ../src/PhonepadPuzzle.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
