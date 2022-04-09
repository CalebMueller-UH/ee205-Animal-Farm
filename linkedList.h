///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file linkedList.h
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   04_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_LINKEDLIST_H
#define EE205_ANIMAL_FARM_LINKEDLIST_H

#include <stdio.h> // For Cout
#include <exception>  // For try/catch blocks
#include <assert.h> // For assert
#include <string.h> // For c style strings

#include "Cat.h"
#include "config.h"
#include "catDatabase.h"

/// @returns True if successful, else False
/// @throws logic_error if newCat is already in database
bool addCat(Cat *newCat);

/// @brief Determines whether a pointer address associated with a Cat already exists in the linked list
/// @param Takes in a Cat pointer as an argument
/// @returns true if the cat is already in the linked list, else false
bool catIsInDatabase(Cat *tCat);

/// @brief Checks the member variable values of all Cat objects found in the linked list for validity
/// @returns true if all of the linked list Cat objects have valid member variable entries, else false
bool validateDatabase();

/// @brief Removes a Cat object from the linked list and deletes the object
/// @param Takes in a Cat object pointer to delete
/// @returns true if the cat was successfully found, removed, and deleted, else false
bool deleteCat(Cat *deleteThisCat);

/// @brief Removes all of the Cat objects from the linked list and deletes them
bool deleteAllCats();

/// @brief Prints member variable information for all Cat objects found in the linked list
/// @returns true if all cat objects in linked list were able to be printed successfully
bool printAllCats();

/// @brief Finds a specific Cat object by the _name variable value
/// @param Takes in a char[] name of the Cat object being sought
/// @returns a type Cat pointer to the first Cat object found matching the passed in argument name
/// or nullptr if a Cat object in the linked list was not found with the name given by testName
Cat* findCatByName(const char* name);


#endif //EE205_ANIMAL_FARM_LINKEDLIST_H
