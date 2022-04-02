///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file addCats.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include "config.h"

int addCat(const char *name,
           const enum Gender gender,
           const enum Breed breed,
           const bool isFixed,
           const Weight weight,
           const enum Color collarColor1,
           const enum Color collarColor2,
           const unsigned long long license)
{
    // Validate the input parameters passed into addCat

    // Test Database Full
    if (currentNumberOfCats > MAX_CATS)
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Error: Database is already full and %s was not able to be added\n", PROGRAM_NAME, name);
#endif
        return BAD_CAT;
    }
    // Test name validity
    if (!nameIsValid(name))
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Error: The name \"%s\" is not a valid input\n", PROGRAM_NAME, name);
#endif
        return BAD_CAT;
    }

    // Test weight validity
    if (!weightIsValid(weight))
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Error: \"%s\" has an invalid weight\n", PROGRAM_NAME, name);
#endif
        return BAD_CAT;
    }

    // Test for collar color validity
    if (!collarColorsAreValid(collarColor1, collarColor2))
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Error: addCat input is invalid!\n", PROGRAM_NAME);
#endif
        return BAD_CAT;
    }

    // Test for a duplicate license number
    if (!licenseIsValid(license))
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Error: addCat input is invalid!\n", PROGRAM_NAME);
#endif
        return BAD_CAT;
    }

    NumCats newCatIndex = currentNumberOfCats;
    currentNumberOfCats++;

    // addCat parameters are valid
    strcpy(cats[newCatIndex].name, name);
    cats[newCatIndex].gender = gender;
    cats[newCatIndex].breed = breed;
    cats[newCatIndex].isFixed = isFixed;
    cats[newCatIndex].weight = weight;
    cats[newCatIndex].collarColor1 = collarColor1;
    cats[newCatIndex].collarColor2 = collarColor2;
    cats[newCatIndex].license = license;
    return newCatIndex;
}

