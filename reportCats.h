///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_REPORTCATS_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_REPORTCATS_H

#include "catDatabase.h"
#include "validate.h"

void printCat(const size_t index);

void printAllCats();

int findCat(const char *name);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_REPORTCATS_H
