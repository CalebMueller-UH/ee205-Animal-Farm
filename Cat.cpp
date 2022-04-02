///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"


const char *Cat::getName() const {
    return _name;
}

Gender Cat::getGender() const {
    return _gender;
}

Breed Cat::getBreed() const {
    return _breed;
}

bool Cat::isCatFixed() const {
    return _catFixed;
}

Weight Cat::getWeight() const {
    return _weight;
}

void Cat::setName(const char *name) {
    strcpy(_name, name);
}

void Cat::fixCat(bool catFixed) {
    _catFixed = catFixed;
}

void Cat::setWeight(Weight weight) {
    _weight = weight;
}

void Cat::setGender(Gender gender) {
    _gender = gender;
}

void Cat::setBreed(Breed breed) {
    _breed = breed;
}

/// Default Cat constructor initializes member variables to default values given in spec document
Cat::Cat() :
        _gender(UNKNOWN_GENDER), _breed(UNKNOWN_BREED), _catFixed(false), _weight(UNKNOWN_WEIGHT)
{
    strcpy(_name, "");
    _next = nullptr;
} // End of default constructor

/// Explicit Cat constructor initializes with user defined values, or
/// If a specific field isn't given, will initialize to a default value
Cat::Cat(const char *name, Gender gender, Breed breed, Weight weight) :
        _gender(gender), _breed(breed), _weight(weight)
{

    if (strlen(name) > MAX_NAME_LEN) {
#ifdef DEBUG_ENABLE
        {
            fprintf(stderr, "%s Constructor Error: invalid name entry, the name %s is greater than the configured max name length", PROGRAM_NAME, *name);
        }
#endif
    }

    strcpy(_name, name);
    _next = nullptr;
} // End of paramaterized constructor

Cat::~Cat()
{
    this->zeroize();
} // End of destructor

/// @returns true if everything worked correctly. false if something goes wrong
bool Cat::print() const noexcept
{

assert(validate());

cout << setw(80) << setfill('=') << "" << endl;
cout << setfill(' ');
cout << left;
cout << boolalpha;
FORMAT_LINE("Cat", "name") << getName() << endl;
FORMAT_LINE("Cat", "gender") << genderLiteral(getGender()) << endl;
FORMAT_LINE("Cat", "breed") << breedLiteral(getBreed()) << endl;
FORMAT_LINE("Cat", "isFixed") << isCatFixed() << endl;
FORMAT_LINE("Cat", "weight") << getWeight() << endl;

return true;
} // End of print()

/// @returns true if all member variables are valid, and
/// false if any of the member variables are invalid.
bool Cat::validate() const {
    bool isValid = true;

    // Validate Name
    // Name must not be nullptr, must not be empty, and must be shorter than MAX_NAME_LEN (checked in constructor before being assigned)
    if (strcmp(_name, nullptr) == 0)
    {
#ifdef DEBUG_ENABLE
            fprintf(stderr, "%s Validate Error: invalid name entry, member name set to nullptr", PROGRAM_NAME);
#endif
        isValid = false;
    }
    if (strcmp(_name, "") == 0)
    {
#ifdef DEBUG_ENABLE
            fprintf(stderr, "%s Validate Error: invalid name entry, member name is empty", PROGRAM_NAME);
#endif
        isValid = false;
    }

    // Validate Gender
    // Gender must not be UNKNOWN_GENDER
    if(_gender == UNKNOWN_GENDER)
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Validate Error: invalid gender entry for %s Cat, gender must be known",
                PROGRAM_NAME, _name);
#endif
        isValid = false;
    }

    // Validate Breed
    // Breed must not be UNKNOWN_BREED
    if(_breed == UNKNOWN_BREED)
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Validate Error: invalid breed entry for %s Cat, breed must be known",
                PROGRAM_NAME, _name);
#endif
        isValid = false;
    }

    // Validate Weight
    // Weight must be greater than 0 and less than MAX_CAT_WEIGHT
    if(_weight <= 0)
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Validate Error: weight entry for %s Cat, weight must be greater than 0",
                PROGRAM_NAME, _name);
#endif
        isValid = false;
    }

    if(_weight > MAX_CAT_WEIGHT)
    {
#ifdef DEBUG_ENABLE
        fprintf(stderr, "%s Validate Error: weight entry for %s Cat, weight must be less than max cat weight",
                PROGRAM_NAME, _name);
#endif
        isValid = false;
    }

    return isValid;
} // End of validate()

void Cat::zeroize()
{
    memset(this, 0, sizeof(Cat));
} // End of zeroize()


const char *genderLiteral(const enum Gender gender)
{
    switch (gender) {
        case (UNKNOWN_GENDER):
            return "UNKNOWN_GENDER";
        case (MALE):
            return "MALE";
        case (FEMALE):
            return "FEMALE";
        default:
            return "\0"; //
    }
} // End of genderLiteral()

const char *breedLiteral(const enum Breed breed)
{
    switch (breed) {
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
} // End of breedLiteral
