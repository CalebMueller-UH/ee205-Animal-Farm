///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H

#include <stdio.h>
#include <exception>  // For try/catch blocks
#include <assert.h> // For assert
#include <string.h>

#include "Cat.h"
#include "config.h"

extern Cat *catListHead;

bool addCat(Cat *newCat);

bool addCat(const char *name, Gender gender, Breed breed, Weight weight);

bool catIsInDatabase(Cat *tCat);


#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H
