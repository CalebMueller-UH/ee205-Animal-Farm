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


const char *Cat::getName() const
{
    return _name;
}

Gender Cat::getGender() const
{
    return _gender;
}

Breed Cat::getBreed() const
{
    return _breed;
}

bool Cat::isCatFixed() const
{
    return _catFixed;
}

Weight Cat::getWeight() const
{
    return _weight;
}

void Cat::setName(const char *name)
{
    if(nameIsValid(name))
        strcpy(_name, name);
}

void Cat::fixCat(bool catFixed)
{
    _catFixed = catFixed;
}

void Cat::setWeight(Weight weight)
{
    if(weightIsValid(weight))
    {
    _weight = weight;
    }
}

void Cat::setGender(Gender gender)
{
    if(genderIsValid(gender))
    {
    _gender = gender;
    }
}

void Cat::setBreed(Breed breed)
{
    if(breedIsValid(breed))
    {
    _breed = breed;
    }
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

void Cat::zeroize()
{
    memset(this, 0, sizeof(Cat));
} // End of zeroize()

/// @returns true if all member variables are valid, and
/// false if any of the member variables are invalid.
bool Cat::validate() const noexcept
{
    try
    {
        // Validate Name
        nameIsValid(_name);
        // Validate Gender
        genderIsValid(_gender);
        // Validate Breed
        breedIsValid(_breed);
        // Validate Weight
        weightIsValid(_weight);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true; // Cat member variables are valid
} // End of validate()


bool Cat::nameIsValid(const char* testName) const
{
    if (testName == nullptr)
    {
        throw invalid_argument(PROGRAM_NAME " Name Validation Error: name is set to NULL");
    }

    if (strlen(testName) <= 0)
    {
        throw length_error(PROGRAM_NAME " Name Validation Error: name is empty");
    }

    if (strlen(testName) > MAX_NAME_LEN)
    {
        throw length_error(PROGRAM_NAME " Name Validation Error: name is too long");
    }
    return true;  // name is valid
} // End of nameIsValid()


bool Cat::genderIsValid(const enum Gender testGender) const
{
    // Gender must not be UNKNOWN_GENDER
    if(testGender == UNKNOWN_GENDER)
    {
        throw invalid_argument(PROGRAM_NAME " Gender Validation Error: Gender must not be set to UNKNOWN_GENDER");
    }

    return true; // gender is valid
}

bool Cat::breedIsValid(const enum Breed testBreed) const
{
    // Breed must not be UNKNOWN_BREED
    if(testBreed == UNKNOWN_BREED)
    {
        throw invalid_argument(PROGRAM_NAME " Breed Validation Error: Breed must not be set to UNKNOWN_BREED");
    }

    return true; // breed is valid
}

bool Cat::weightIsValid(const Weight testWeight) const
{
    if(testWeight == UNKNOWN_WEIGHT)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight is set to UNKNOWN_WEIGHT");
    }

    if(testWeight <=0)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight must be greater than 0");
    }

    if(testWeight > MAX_CAT_WEIGHT)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight must be less than MAX_CAT_WEIGHT");
    }

    return true; // weight is valid
}


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
