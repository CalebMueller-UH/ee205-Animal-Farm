///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H


#include <iomanip> // For print() formatting
#include <iostream> // For cout

#include <assert.h> // For assert
#include <string.h> // For working with C style strings

#include "config.h"

using namespace std;

/// Maximum Name Length that a cat is allowed to have
#define MAX_NAME_LEN 30

/// Maximum Weight that a cat is allowed to have
#define MAX_CAT_WEIGHT 1000

/// Default weight of a cat before being assigned
#define UNKNOWN_WEIGHT -1

/// Format a line for printing the members of a class
#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

enum Gender {
    UNKNOWN_GENDER,
    MALE,
    FEMALE
};

enum Breed {
    UNKNOWN_BREED,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};

typedef float Weight;

class Cat {
protected:            /////////////// Protected Member Variables ///////////////
        char _name[MAX_NAME_LEN]; ///< Name of cat
        enum Gender _gender; ///< Gender of cat
        enum Breed _breed; ///< Breed of cat
        bool _catFixed; ///< True if cat is spayed/neutered
        Weight _weight; ///< Weight of cat: =-1 if unknown, 0 < _weight < MAX_CAT_WEIGHT

public:            /////////////// Public Member Variables ///////////////
        Cat *_next; /// Pointer to next cat for single linked list

public:            /////////////// Getters ///////////////
        const char *getName() const;

        Gender getGender() const;

        Breed getBreed() const;

        bool isCatFixed() const;

        Weight getWeight() const;

public:            /////////////// Public Setters //////////////////
        void setName(const char *name);

        void setCatFixed(bool catFixed);

        void setWeight(Weight weight);

protected:            /////////////// Protected Setters ///////////////
        void setGender(Gender gender);

        void setBreed(Breed breed);

public:            /////////////// Constructors & Destructors //////////////////
        Cat();

        Cat(const char *name, Gender gender = UNKNOWN_GENDER, Breed breed = UNKNOWN_BREED, Weight weight = UNKNOWN_WEIGHT);

        virtual ~Cat();

public:            /////////////// Public Methods //////////////////
        bool print() const noexcept;

        bool validate() const;
}; // End of Cat class


/// Returns a character literal for use in communicating the gender of a cat to the user
const char *genderLiteral(const enum Gender gender);

/// Returns a character literal for use in communicating the breed of a cat to the user
const char *breedLiteral(const enum Breed breed);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
