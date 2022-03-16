///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file validate.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "validate.h"
#include "config.h"

bool nameIsValid(const char *name)
{
    // Check to see if name is unique
    for (size_t i = 0; i < currentNumberOfCats; ++i)
    {
        if (strcmp(cats[i].name, name) == 0)
        {
            fprintf(stderr, "%s Error: There already exists a cat in the database with the name %s!\n", PROGRAM_NAME, name);
            return false;
        }
    }

    // Check to see if name is null
    if (name == NULL)
    {
        fprintf(stderr, "%s Error: NULL name is invalid %s!\n", PROGRAM_NAME, name);
        return false;
    }

    // Check to see if name is empty
    if (strcmp(name, "") == 0)
    {
        return false;
    }

    // Check to see if name is too long
    if (strlen(name) >= MAX_NAME_LEN)
    {
        return false;
    }

    return true;
}

bool weightIsValid(const float weight)
{
    if (weight > 0 && weight < MAX_CAT_WEIGHT)
    {
        return true; // weight is valid
    }
    fprintf(stderr, "%s Error: An invalid weight assignment has been attempted!\n", PROGRAM_NAME);
    return false; // weight is invalid
}

bool indexIsValid(const size_t index)
{
    if (index >= currentNumberOfCats)
    {
        fprintf(stderr, "%s Error: Access to an out-of-range index has been attempted!\n", PROGRAM_NAME);
        return false;
    }

    return true;
}

bool collarColorsAreValid(const enum Color testCollar1, const enum Color testCollar2)
{
    // Ensure that for a given cat, collarColor1 != collarColor2
    if (testCollar1 == testCollar2)
    {
        fprintf(stderr, "%s Error: Collar colors for a given cat must be different colors!\n", PROGRAM_NAME);
        return false; // invalid collar colors
    }

    // Ensure there are no duplicate cat collars (the combination of collarColor1 and collarColor2)
    for (size_t i = 0; i < currentNumberOfCats; ++i)
    {
        enum Color compareCollar1 = cats[i].collarColor1;
        enum Color compareCollar2 = cats[i].collarColor2;

        if ((testCollar1 == compareCollar1 && testCollar2 == compareCollar2) ||
            (testCollar1 == compareCollar2 && testCollar2 == compareCollar1))
        {
            fprintf(stderr, "%s Error: The Collar Color combination of %s and %s is not unique!\n", PROGRAM_NAME, colorLiteral(testCollar1), colorLiteral(testCollar2));
            return false; // invalid collar colors
        }
    }

    // Tests have succeeded, and collar colors are valid
    return true;
}

bool licenseIsValid(const unsigned long long licenseNum)
{
    for (size_t i = 0; i < currentNumberOfCats; ++i)
    {
        if (cats[i].license == licenseNum)
        {
            fprintf(stderr, "%s Error: License is not unique!\n", PROGRAM_NAME);
            return false; // invalid license
        }
    }
    return true; // license is valid
}

