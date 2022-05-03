cmake_minimum_required(VERSION 3.0.0)
project(Twitter VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Twitter
        functions.c
        linked_list.c
        main.c
        objects.h
        user_functions.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
