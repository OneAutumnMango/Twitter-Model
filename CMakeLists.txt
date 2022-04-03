cmake_minimum_required(VERSION 3.21)
project(Twitter C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Twitter
        functions.c
        linked_list.c
        objects.h
        user_functions.c)
