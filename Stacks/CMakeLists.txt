cmake_minimum_required(VERSION 3.28)
project(Data_Structures C)

set(CMAKE_C_STANDARD 11)


add_subdirectory(array)
add_subdirectory(linked_list)
add_executable(new_target array/main.c)
