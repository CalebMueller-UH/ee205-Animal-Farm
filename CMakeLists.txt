###############################################################################
###         University of Hawaii, College of Engineering
### @brief  ee205-Animal-Farm - EE 205 - Spr 2022
###
### @file CMakeLists.txt
### @version 3.0
###
### @author Caleb Mueller <mc61@hawaii.edu>
### @date 23_Apr_2022
###############################################################################

cmake_minimum_required(VERSION 3.22)
project(ee205_animal_farm)

set(CMAKE_CXX_SCREAMDARD 14)
set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG_ENABLE")

# Animal Farm 3.0 Build
add_executable(
        ee205_animal_farm_3_0
        main.cpp
        Animal.h Animal.cpp
        Cat.h Cat.cpp
        Node.h Node.cpp
        List.cpp List.h
        Mammal.h Mammal.cpp
        SinglyLinkedList.cpp SinglyLinkedList.h
        Weight.h Weight.cpp)

# List Testing
add_executable(
        List_Testing
        main_list_testing.cpp
        Animal.h Animal.cpp
        Cat.h Cat.cpp
        Node.h Node.cpp
        List.cpp List.h
        Mammal.h Mammal.cpp
        SinglyLinkedList.cpp SinglyLinkedList.h
        Weight.h Weight.cpp)
