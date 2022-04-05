///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file linkedList.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   04_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LINKEDLIST_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LINKEDLIST_H

#include <stdio.h> // For Cout
#include <exception>  // For try/catch blocks
#include <assert.h> // For assert
#include <string.h> // For c style strings

#include "Cat.h"
#include "config.h"
#include "catDatabase.h"

bool addCat(Cat *newCat);

bool addCat(const char *name, Gender gender, Breed breed, Weight weight);

bool catIsInDatabase(Cat *tCat);

/// @brief Iterates over every cat in the linked list and calls validate()
/// @returns true if all members of the linked list are valid, else false
bool validateDatabase();

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LINKEDLIST_H
