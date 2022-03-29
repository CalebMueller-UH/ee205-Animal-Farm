///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "updateCats.h"
#include "config.h"

bool fixCat(const NumCats index)
{
    cats[index].isFixed = true;
    return true;
}

bool updateCatName(const NumCats index, const char *newName)
{
    if (nameIsValid(newName))
    {
        strcpy(cats[index].name, newName);
        return true;
    }
    return false;
}

bool updateCatWeight(const NumCats index, const Weight newWeight)
{
    if (weightIsValid(newWeight))
    {
        cats[index].weight = newWeight;
        return true;
    }
    return false;
}

bool updateCatCollar1(const NumCats index, const enum Color newColor)
{
    if (!indexIsValid(index))
    {
        fprintf(stderr, "%s Error: updateCatCollar1 index is invalid\n", PROGRAM_NAME);
        return false;
    }

    // Check to see if the color combination of the newColor for collar1 and any of the collar2 database entries is invalid
    if (!collarColorsAreValid(newColor, cats[index].collarColor2))
    {
        fprintf(stderr, "%s Error: updateCatCollar1 collar colors are invalid\n", PROGRAM_NAME);
        return false;
    }
    cats[index].collarColor1 = newColor;
    return true;
}

bool updateCatCollar2(const NumCats index, const enum Color newColor)
{
    if (!indexIsValid(index))
    {
        fprintf(stderr, "%s Error: updateCatCollar2 index is invalid\n", PROGRAM_NAME);
        return false;
    }

    // Check to see if the color combination of the newColor for collar2 and any of the collar1 database entries is invalid
    if (!collarColorsAreValid(cats[index].collarColor1, newColor))
    {
        fprintf(stderr, "%s Error: updateCatCollar2 collar colors are invalid\n", PROGRAM_NAME);
        return false;
    }
    cats[index].collarColor2 = newColor;
    return true;
}

bool updateLicense(const NumCats index, const unsigned long long int newLicense)
{
    if (!indexIsValid(index))
    {
        fprintf(stderr, "%s Error: updateLicense index is invalid\n", PROGRAM_NAME);
        return false;
    }
    if (!licenseIsValid(newLicense))
    {
        fprintf(stderr, "%s Error: updateLicense license number is invalid\n", PROGRAM_NAME);
        return false;
    }
    cats[index].license = newLicense;
    return true;
}

