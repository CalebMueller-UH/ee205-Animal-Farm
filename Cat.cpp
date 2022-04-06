///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 2.0
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
    return (Weight)_weight;
}

void Cat::setName(const char *name)
{
    if(nameIsValid(name))
    {
        strcpy(_name, name);
    }
}

void Cat::fixCat()
{
    _catFixed = true;
}

void Cat::setWeight(Weight weight)
{
    try
    {
        if(weightIsValid(weight))
        {
            _weight = (Weight)(weight);
        }
    }catch(const std::exception &e){
        cout << e.what() << endl;
    }

}

void Cat::setGender(Gender gender)
{
    try
    {
        this->genderIsValid(gender);
    } catch (const std::exception &e){
        cout << e.what() << endl;
        return;
    }
    if(gender != UNKNOWN_GENDER && _gender == UNKNOWN_GENDER)
    {
        _gender = gender;
    }
}

void Cat::setBreed(Breed breed)
{
    try
    {
        this->breedIsValid(breed);
    }catch(const std::exception &e){
        cout << e.what() << endl;
        return;
    }
    if(breed != UNKNOWN_BREED && _breed == UNKNOWN_BREED)
    {
        _breed = breed;
    }
}

///> Explicit Cat constructor initializes with user defined values
/// If a specific field isn't given, will initialize to a default value
Cat::Cat(const char *name, Gender gender, Breed breed, Weight weight) :
        _gender(gender), _breed(breed), _weight(weight)
{
    strcpy(_name, name);
    _next = nullptr;
} // End of explicit constructor

/// Default Cat constructor initializes member variables to default values given in spec document
Cat::Cat() :
        Cat{DEFAULT_NAME ,UNKNOWN_GENDER, UNKNOWN_BREED, UNKNOWN_WEIGHT}{
} // End of default constructor

Cat::~Cat()
{
    this->zeroize();
} // End of destructor

/// @returns true if everything worked correctly. false if something goes wrong
bool Cat::print() const noexcept
{
    assert(validate());

    using namespace std;
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
    char zeroName[MAX_NAME_LEN];
    memset(zeroName, '0', MAX_NAME_LEN);
    this->setName(zeroName);
    this->_gender = UNKNOWN_GENDER;
    this->_breed = UNKNOWN_BREED;
    this->_catFixed = false;
    this->_weight = UNKNOWN_WEIGHT;
} // End of zeroize()

/// @returns true if all member variables are valid
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

/// @returns true if member variable _name is a valid entry
bool Cat::nameIsValid(const char* testName) const
{
    if (testName == nullptr)
    {
        throw invalid_argument(PROGRAM_NAME " Name Validation Error: name is set to nullptr!");
    }

    if (strlen(testName) <= 0)
    {
        throw length_error(PROGRAM_NAME " Name Validation Error: name is empty!");
    }

    if (strlen(testName) > MAX_NAME_LEN)
    {
        throw length_error(PROGRAM_NAME " Name Validation Error: name is too long!");
    }
    return true;  // name is valid
} // End of nameIsValid()

/// @returns true if member variable _gender is a valid entry
bool Cat::genderIsValid(const enum Gender testGender) const
{
    // Gender must not be UNKNOWN_GENDER
    if(testGender == UNKNOWN_GENDER)
    {
        throw invalid_argument(PROGRAM_NAME " Gender Validation Error: Gender must not be set to UNKNOWN_GENDER!");
    }
    return true; // gender is valid
}

/// @returns true if member variable _breed is a valid entry
bool Cat::breedIsValid(const enum Breed testBreed) const
{
    // Breed must not be UNKNOWN_BREED
    if(testBreed == UNKNOWN_BREED)
    {
        throw invalid_argument(PROGRAM_NAME " Breed Validation Error: Breed must not be set to UNKNOWN_BREED!");
    }

    return true; // breed is valid
}

/// @returns true if member variable _weight is a valid entry
bool Cat::weightIsValid(const Weight testWeight) const
{
    if(testWeight == UNKNOWN_WEIGHT)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight is set to UNKNOWN_WEIGHT!");
    }

    if(testWeight <=0)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight must be greater than 0!");
    }

    if(testWeight > MAX_CAT_WEIGHT)
    {
        throw invalid_argument( PROGRAM_NAME " Weight Validation Error: Weight must be less than MAX_CAT_WEIGHT!");
    }

    return true; // weight is valid
}

/// @returns c style string literal of type enum Gender corresponding to parameter input
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

/// @returns c style string literal of type enum Breed corresponding to parameter input
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
