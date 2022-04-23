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

/////////////////////////////////// Constants ///////////////////////////////////
static const std::string SPECIES_NAME = "Felis catus";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Cat::Cat( const std::string &newName )
		:
		Cat( newName, Color::UNKNOWN_COLOR, false, Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, Weight::DEFAULT_MAX_WEIGHT ) {}

Cat::Cat( const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const float newWeight,
          const float newMaxWeight ) : Mammal( newColor, newGender, newWeight, newMaxWeight, Cat::SPECIES_NAME ), _name{ newName } {}

/////////////////////////////////// Getters ///////////////////////////////////
std::string Cat::getName() const noexcept
{
	return _name;
}

bool Cat::isFixed() const noexcept
{
	return false;
}

/////////////////////////////////// Setters ///////////////////////////////////
void Cat::setName( const std::string &newName )
{

}

void Cat::fixCat() noexcept
{

}

/////////////////////////////////// Public Methods ///////////////////////////////////
std::string Cat::speak() const noexcept
{
	return nullptr;
}

void Cat::dump() const noexcept
{
	Mammal::dump();
}

/////////////////////////////////// Validation Methods ///////////////////////////////////
bool Cat::validate() const noexcept
{
	return Animal::validate();
}

bool Cat::validateName( const std::string &newName )
{
	return false;
}




