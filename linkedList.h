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

/// @brief Iterates over linked list objects and tests for duplicates
/// @returns true if the passed in object does not have a duplicate address already within the linked list
bool catIsInDatabase(Cat *tCat);

/// @brief Iterates over every cat in the linked list and calls validate()
/// @returns true if all members of the linked list are valid, else false
bool validateDatabase();

/// @brief Deletes the cat found at the Cat object address passed in to the function
/// @returns true if operation was successful, else false
bool deleteCat(Cat *deleteThisCat);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LINKEDLIST_H