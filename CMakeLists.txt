cmake_minimum_required(VERSION 4.1)
project(Programming_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(Programming_Project main.c waveform.c io.c)
target_link_libraries(Programming_Project m)