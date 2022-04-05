///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file catDatabase.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "catDatabase.h"

#include "config.h"

/// Head pointer for linked list of cats
Cat *catListHead = nullptr;

/// @return True if successful, else False
/// @throws logic_error if newCat is already in database
bool addCat(Cat* newCat)
{
    assert(newCat != nullptr);
    newCat ->validate();

    /*
    if(catIsInDatabase(newCat))
    {
        throw logic_error( PROGRAM_NAME ": Cat is already in database!");
    }
    */
    return true;
}


/// @return True if successful, else False
/// @throws logic_error if newCat is already in database
bool addCat(const char *name, Gender gender, Breed breed, Weight weight)
{
    Cat* aNewCat = new Cat(name, gender, breed, weight);

    bool addWasSuccessful = addCat(aNewCat);
    return addWasSuccessful;
}

bool catIsInDatabase(Cat *tCat)
{
    Cat* curCat = catListHead;
    while(curCat != nullptr)
    {
        if(tCat == curCat)
        {
            return false; // Duplicate found, cat already exists in database
        }
        curCat = curCat->_next;
    }
    return true;
}

