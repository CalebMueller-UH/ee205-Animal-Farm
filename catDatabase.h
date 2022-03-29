///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <time.h> //For Birthday
#include <locale.h>

#define MAX_CATS 1024
#define MAX_NAME_LEN 50
#define MAX_CAT_WEIGHT 1000

typedef float Weight;

typedef size_t NumCats;

extern NumCats currentNumberOfCats;

enum Gender
{
    UNKNOWN_GENDER,
    MALE,
    FEMALE
};

enum Breed
{
    UNKNOWN_BREED,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};

enum Color
{
    UNASSIGNED,
    BLACK,
    WHITE,
    RED,
    BLUE,
    GREEN,
    PINK
};

struct Cat
{
    char name[MAX_NAME_LEN];
    enum Gender gender;
    enum Breed breed;
    Weight weight;
    bool isFixed;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
};

extern struct Cat cats[];

extern void initializeDatabase();

char *genderLiteral(const enum Gender gender);

char *breedLiteral(const enum Breed breed);

char *colorLiteral(const enum Color color);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H
