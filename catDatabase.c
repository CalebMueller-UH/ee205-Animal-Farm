///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "catDatabase.h"

#include "config.h"

size_t currentNumberOfCats = 0;

struct Cat cats[MAX_CATS];

void initializeDatabase()
{
    currentNumberOfCats = 0;
    memset(&cats, 0, sizeof(cats));
}

char *genderLiteral(const enum Gender gender)
{
    switch (gender)
    {
        case (UNKNOWN_GENDER):
            return "UNKNOWN_GENDER";
        case (MALE):
            return "MALE";
        case (FEMALE):
            return "FEMALE";
        default:
            return "\0"; //
    }
}

char *breedLiteral(const enum Breed breed)
{
    switch (breed)
    {
        case (UNKNOWN_BREED):
            return "UNKNOWN_BREED";
        case (MAINE_COON):
            return "MAINE_COON";
        case (MANX):
            return "MANX";
        case (SHORTHAIR):
            return "SHORTHAIR";
        case (PERSIAN):
            return "PERSIAN";
        case (SPHYNX):
            return "SPHYNX";
        default:
            return "\0";
    }
}

char *colorLiteral(const enum Color color)
{
    switch (color)
    {
        case (UNASSIGNED):
            return "UNASSIGNED";
        case (BLACK):
            return "BLACK";
        case (WHITE):
            return "WHITE";
        case (RED):
            return "RED";
        case (BLUE):
            return "BLUE";
        case (GREEN):
            return "GREEN";
        case (PINK):
            return "PINK";
        default:
            return "\0";
    }
}
