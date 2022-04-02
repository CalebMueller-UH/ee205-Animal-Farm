///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file deleteCats.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "deleteCats.h"
#include "catDatabase.h"
#include "config.h"

void deleteAllCats()
{
    initializeDatabase();
}

int deleteCat(const NumCats index)
{
    if (indexIsValid(index) == false)
    {
        fprintf(stderr, "%s Error: deleteCat was not able to execute\n", PROGRAM_NAME);
        return BAD_CAT;
    }

    cats[index] = cats[currentNumberOfCats - 1];

    memset(&cats[currentNumberOfCats], 0, sizeof(struct Cat));

    currentNumberOfCats--;

    return 1;
}

