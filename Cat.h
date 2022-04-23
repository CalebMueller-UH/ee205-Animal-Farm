///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H


#include <iomanip> // For print() formatting
#include <iostream> // For cout
#include <exception>  // For try/catch blocks

#include <assert.h> // For assert
#include <string.h> // For working with C style strings

<<<<<<< HEAD
=======
#include "Mammal.h"
>>>>>>> f9fc5e6 (Animal Farm 3.0 ~New Beginnings~  Fresh start: stubbing out header files from specification requirements.)
#include "config.h"

using namespace std;

<<<<<<< HEAD


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
        Cat *_next; ///< Pointer to next cat for single linked list
                    /// This pointer is temporary to animal farm 2
                    /// @todo fix public next pointer in future versions

public:            /////////////// Getters ///////////////
        const char *getName() const; ///< Get cats name

        Gender getGender() const; ///< Get cats gender

        Breed getBreed() const; ///< Get cats breed

        bool isCatFixed() const; ///< Returns true if cat is fixed

        Weight getWeight() const; ///< Get cats weight

public:            /////////////// Public Setters //////////////////
        void setName(const char *name); ///< Set cat name

        void fixCat(); ///< set catFixed to true

        void setWeight(Weight weight); ///< Set cat weight

protected:            /////////////// Protected Setters ///////////////
public: ////// @todo Once administrative setter object is implemented change these back to Protected!!
        void setGender(Gender gender); ///< Set cat gender

        void setBreed(Breed breed); ///< Set cat breed

public:            /////////////// Constructors & Destructors //////////////////
        ///< Creates a cat with user defined member values
        Cat(const char *name, Gender gender = UNKNOWN_GENDER, Breed breed = UNKNOWN_BREED, Weight weight = UNKNOWN_WEIGHT);

        ///< Creates a cat with default member values using delegated constructor
        Cat();

        ///< Destructor zeroizes member data prior to deleting reference to object to prevent "sensitive"
        ///< data from being present in memory
        virtual ~Cat();

public:            /////////////// Public Methods //////////////////
        bool print() const noexcept; ///< Prints cat information

        bool validate() const noexcept; ///< Checks the validity of cat member data fields

private:            /////////////// Private Methods //////////////////
    void zeroize(); ///< Sets member data to zero, used by destructor

public:            /////////////// Validation Methods //////////////////
        static bool nameIsValid(const char* testName);
        static bool genderIsValid(const enum Gender testGender);
        static bool breedIsValid(const enum Breed testBreed);
        static bool weightIsValid(const Weight testWeight);
=======
class Cat : public Mammal
{

	/////////////////////////////////// Enumerations ///////////////////////////////////

private: //////////////////////////////// Member Variables ////////////////////////////////
	std::string name;
	bool catIsFixed;

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const std::string SPECIES_NAME;
	static const Weight MAX_WEIGHT;

public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	Cat( const std::string &newName );

	Cat( const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight newWeight );

public:  /////////////////////////////////// Getters ///////////////////////////////////
	std::string getName() const noexcept;

	bool isFixed() const noexcept;

public:  /////////////////////////////////// Setters ///////////////////////////////////
	void setName( const std::string &newName );

	void fixCat() noexcept;

public:  /////////////////////////////////// Public Methods ///////////////////////////////////
	std::string speak() const noexcept override;

	void dump() const noexcept override;

public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
	bool validate() const noexcept override;

	static bool validateName( const std::string &newName );
>>>>>>> f9fc5e6 (Animal Farm 3.0 ~New Beginnings~  Fresh start: stubbing out header files from specification requirements.)


}; // End of Cat class

<<<<<<< HEAD

/// Returns a character literal for use in communicating the gender of a cat to the user
const char *genderLiteral(const enum Gender gender);

/// Returns a character literal for use in communicating the breed of a cat to the user
const char *breedLiteral(const enum Breed breed);

=======
>>>>>>> f9fc5e6 (Animal Farm 3.0 ~New Beginnings~  Fresh start: stubbing out header files from specification requirements.)
#endif //EE205_ANIMAL_FARM_CAT_H
