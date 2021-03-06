///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date 23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"

/////////////////////////////////// Constants ///////////////////////////////////
const string Cat::SPECIES_NAME = "Felis catus";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Cat::Cat( const string &newName )
		: Cat( newName, Color::UNKNOWN_COLOR, false, Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, Weight::DEFAULT_MAX_WEIGHT )
{}

Cat::Cat( const string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const t_weight newWeight )
		: Cat( newName, newColor, newIsFixed, newGender, newWeight, Weight::DEFAULT_MAX_WEIGHT )
{}

Cat::Cat(

		const string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const t_weight newWeight, const t_weight newMaxWeight )
		: Mammal( newColor, newGender, newWeight, newMaxWeight, Cat::SPECIES_NAME ), _name{
		newName
}, _catIsFixed{
		newIsFixed
}
{
}

/////////////////////////////////// Getters ///////////////////////////////////
string Cat::getName() const noexcept
{
	return _name;
}

bool Cat::isFixed() const noexcept
{
	return _catIsFixed;
}

/////////////////////////////////// Setters ///////////////////////////////////
void Cat::setName( const string &newName )
{
	nameIsValid( newName ) ? _name = newName : 0;
}

void Cat::fixCat() noexcept
{
	_catIsFixed = true;
}

/////////////////////////////////// Public Methods ///////////////////////////////////
string Cat::speak() const noexcept
{
	return "The Cat named " + getName() + " says \"Meow!\"";
}

void Cat::dump() const noexcept
{
	PRINT_HEADING_FOR_DUMP;
	Mammal::dump();
	FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << _name << std::endl;
	FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << std::boolalpha << _catIsFixed << std::endl;
}

/////////////////////////////////// Validation Methods ///////////////////////////////////
bool Cat::validate() const noexcept
{
	Mammal::validate();
	assert( nameIsValid( _name ) );
	return true; // is Valid
}

bool Cat::nameIsValid( const string &newName )
{
	int nameLen = newName.length();
	if( nameLen > 0 )
	{
		return true; // name is valid
	}
	return false; // name is invalid
}




