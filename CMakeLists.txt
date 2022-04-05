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
project(ee205_lab_08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ee205_lab_08d_animal_farm_1_to_clion
        main.cpp
        Cat.h Cat.cpp
        catDatabase.h catDatabase.cpp
        config.h
        linkedList.h linkedList.cpp)