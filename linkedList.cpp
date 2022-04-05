///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file linkedList.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   04_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "linkedList.h"

/// @return True if successful, else False
/// @throws logic_error if newCat is already in database
bool addCat(Cat* newCat)
{
    assert(newCat != nullptr);
    newCat ->validate();

    if(catIsInDatabase(newCat))
    {
        throw logic_error( PROGRAM_NAME " addCat Error: Cat is already in database!");
    }
    newCat->_next = catListHead;
    catListHead = newCat;
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
            return true; // Duplicate found, cat already exists in database
        }
        curCat = curCat->_next;
    }
    return false;
}

bool validateDatabase()
{
    Cat *currCat = catListHead;
    while(currCat != nullptr)
    {
        cout << "Validating " << currCat->getName() << endl;
        if(!currCat->validate())
        {
            return false;
        }
        currCat = currCat->_next;
    }
    return true;
}
