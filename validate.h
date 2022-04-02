///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file validate.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_VALIDATE_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_VALIDATE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "catDatabase.h"

bool nameIsValid(const char *name);

bool weightIsValid(const Weight weight);

bool indexIsValid(const NumCats index);

bool collarColorsAreValid(const enum Color collar1, const enum Color collar2);

bool licenseIsValid(const unsigned long long licenseNum);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_VALIDATE_H
