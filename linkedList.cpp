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
    validateDatabase();

    assert(newCat != nullptr);
    newCat ->validate();

    if(catIsInDatabase(newCat))
    {
        throw logic_error( PROGRAM_NAME " addCat Error: Cat is already in database!");
    }

    newCat->_next = catListHead;
    catListHead = newCat;

    validateDatabase();
    return true;
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
        if(!currCat->validate())
        {
            return false;
        }
        currCat = currCat->_next;
    }
    return true;
}

bool deleteCat(Cat *deleteThisCat)
{
    Cat *prevCat = nullptr;
    Cat *currCat = catListHead;

    while(currCat != nullptr)
    {
        if(currCat == deleteThisCat)
        {
            // Check for special case where deleteThisCat is the head item in the list
            if(currCat->_next == nullptr && prevCat == nullptr)
            {
                catListHead = currCat->_next;
                delete currCat;
                return true; //
            }

            // Found the cat to be deleted, and isn't head of list
            // Splice out and delete
            prevCat->_next = currCat->_next;
            delete currCat;
            return true;
        }
        prevCat = currCat;
        currCat = currCat->_next;
    }
    return false; // Was not able to find specified Cat object to delete
} // End of deleteCat()

void printAllCats()
{
    Cat *currCat = catListHead;

    while(currCat != nullptr)
    {
        currCat->print();
        currCat = currCat->_next;
    }
}

