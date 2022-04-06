///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file linkedList.cpp
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   04_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "linkedList.h"

/// @returns True if successful, else False
/// @throws logic_error if newCat is already in database
bool addCat(Cat* newCat)
{
    if(!validateDatabase())
    {
        return false;
    }

    assert(newCat != nullptr);
    newCat ->validate();

    if(catIsInDatabase(newCat))
    {
        throw logic_error( PROGRAM_NAME " addCat Error: Cat is already in database!");
    }

    newCat->_next = catListHead;
    catListHead = newCat;

    if(!validateDatabase())
    {
        return false;
    }

    return true;
}

/// @brief Determines whether a pointer address associated with a Cat already exists in the linked list
/// @param Takes in a Cat pointer as an argument
/// @returns true if the cat is already in the linked list, else false
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

/// @brief Checks the member variable values of all Cat objects found in the linked list for validity
/// @returns true if all of the linked list Cat objects have valid member variable entries, else false
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

/// @brief Removes a Cat object from the linked list and deletes the object
/// @param Takes in a Cat object pointer to delete
/// @returns true if the cat was successfully found, removed, and deleted, else false
bool deleteCat(Cat *deleteThisCat)
{
    if(!validateDatabase())
    {
        return false;
    }

    Cat *prevCat = nullptr;
    Cat *currCat = catListHead;

    while(currCat != nullptr)
    {
        if(currCat == deleteThisCat)
        {
            // Check for special case where deleteThisCat is the head item in the list
            if( prevCat == nullptr)
            {
                catListHead = currCat->_next;
                delete currCat;
                return true; //
            }

            // Found the cat to be deleted, and isn't head of list
            // Splice out and delete
            prevCat->_next = currCat->_next;
            delete currCat;

            if(!validateDatabase())
            {
                return false;
            }
            return true;  // Target found and eliminated, rtb
        }
        // currCat is not the Cat we're looking for, iterate to next link in list
        prevCat = currCat;
        currCat = currCat->_next;
    }
    return false; // Was not able to find specified Cat object to delete
} // End of deleteCat()

/// @brief Removes all of the Cat objects from the linked list and deletes them
bool deleteAllCats()
{
    if(!validateDatabase())
    {
        return false;
    }
    Cat *currCat = catListHead;

    while(catListHead != nullptr)
    {
        currCat = catListHead;
        catListHead = currCat->_next;
        delete currCat;
    }
    if(!validateDatabase())
    {
        return false;
    }
    return true;
} // End of deleteAllCats()

/// @brief Prints member variable information for all Cat objects found in the linked list
/// @returns true if all cat objects in linked list were able to be printed successfully
bool printAllCats()
{
    Cat *currCat = catListHead;

    while(currCat != nullptr)
    {
        if(!currCat->print())
        {
            return false;
        }
        currCat = currCat->_next;
    }
    return true;
} // End of printAllCats()

/// @brief Finds a specific Cat object by the _name variable value
/// @param Takes in a char[] name of the Cat object being saught
/// @returns a type Cat pointer to the first Cat object found matching the passed in argument name
Cat* findCatByName(const char* testName)
{
    Cat *currCat = catListHead;

    while(currCat != nullptr)
    {
        if(strcmp(currCat->getName(), testName) == 0)
        {
            return currCat;
        }
        currCat = currCat->_next;
    }
    return nullptr;
} // End of findCatByName


