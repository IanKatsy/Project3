cmake_minimum_required(VERSION 3.25)
project(Project3 C)

set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(
        pgmDraw.c
        pgm.h sources/image.c sources/main_loop.c pgmDraw.c)