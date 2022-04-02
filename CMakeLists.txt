cmake_minimum_required(VERSION 3.22)
project(ee205_lab_08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ee205_lab_08d_animal_farm_1_to_clion
        main.cpp
        addCats.h addCats.cpp
        Cat.h Cat.cpp
        catDatabase.h catDatabase.cpp
        config.h
        deleteCats.h deleteCats.cpp
        reportCats.h reportCats.cpp
        updateCats.h updateCats.cpp
        validate.h validate.cpp )
