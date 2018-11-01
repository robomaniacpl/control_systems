cmake_minimum_required(VERSION 3.0)
project(Tracz C)

enable_testing()
set(CMAKE_C_FLAGS "-Wall -Werror -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -std=c11 ")

add_subdirectory(valve_control)
add_subdirectory(motor_control)
