###############################################################################
###         University of Hawaii, College of Engineering
### @brief  ee205-Animal-Farm - EE 205 - Spr 2022
###
### @file CMakeLists.txt
### @version 2.0
###
### @author Caleb Mueller <mc61@hawaii.edu>
### @date   02_Apr_2022
###############################################################################

cmake_minimum_required(VERSION 3.22)
project(ee205_animal_farm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG_ENABLE")

#@todo remove this build before release of v3.0
# Animal Farm 3.0 Intermediary Development Build
add_executable(
        ee205_animal_farm_interDev
        main_interDev.cpp
        Node.h Node.cpp
        Animal.h Animal.cpp
        Mammal.h Mammal.cpp
        Cat.h Cat.cpp
        Weight.h Weight.cpp)

# Debug Build
add_executable(
        ee205_animal_farm_debug
        main_debug.cpp
        Cat.h Cat.cpp
        catDatabase.h catDatabase.cpp
        config.h
        linkedList.h linkedList.cpp Animal.cpp)

# Release Build
add_executable(
        ee205_animal_farm_release
        main_release.cpp
        Cat.h Cat.cpp
        catDatabase.h catDatabase.cpp
        config.h
        linkedList.h linkedList.cpp Animal.cpp)