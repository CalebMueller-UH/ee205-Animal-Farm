///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.c
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "reportCats.h"
#include "config.h"

void printCat(const size_t index)
{
    if (indexIsValid(index) == true)
    {
        printf("cat index = [%lu] name=[%s] gender = [%s] breed = [%s] isFixed = [%d] weight = [%.3f] collarColor1 = [%s] collarColor2 = [%s] license[%llu]\n",
               index,
               cats[index].name,
               genderLiteral(cats[index].gender),
               breedLiteral(cats[index].breed),
               cats[index].isFixed,
               cats[index].weight,
               colorLiteral(cats[index].collarColor1),
               colorLiteral(cats[index].collarColor2),
               cats[index].license);
    }
}

void printAllCats()
{
    for (size_t index = 0; index < currentNumberOfCats; ++index)
    {
        printCat(index);
    }
}

int findCat(const char *name)
{
    for (size_t i = 0; i < currentNumberOfCats; ++i)
    {
        if (strcmp(name, cats[i].name) == 0)
        {
            return i;
        }
    }
    fprintf(stderr, "%s Error: No cat in the database was found with the name \"%s\"\n", PROGRAM_NAME, name);
    return BAD_CAT;
}

