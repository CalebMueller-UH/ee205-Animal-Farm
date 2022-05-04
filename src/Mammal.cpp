///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

/////////////////////////////////// Constants ///////////////////////////////////
const string Mammal::MAMMAL_NAME = "Mammilian";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Mammal::Mammal( const t_weight newMaxWeight, const string &newSpecies )
		: Mammal( Color::UNKNOWN_COLOR, Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, newMaxWeight, newSpecies )
{}

Mammal::Mammal( const Color newColor, const Gender newGender, const t_weight newWeight, const t_weight newMaxWeight, const string newSpecies )
		: Animal( newGender, newWeight, newMaxWeight, Mammal::MAMMAL_NAME, newSpecies ), _color{newColor}
{}

/////////////////////////////////// Getters ///////////////////////////////////
Color Mammal::getColor() const noexcept
{
	return _color;
}

/////////////////////////////////// Setters ///////////////////////////////////
void Mammal::setColor( const Color newColor ) noexcept
{
	_color = newColor;
}

/////////////////////////////////// Public Methods ///////////////////////////////////
void Mammal::dump() const noexcept
{
	Animal::dump();
	FORMAT_LINE_FOR_DUMP( "Mammal", "_color" ) << _color << std::endl;
}

/////////////////////////////////// Externally Scoped Overloaded Operators ///////////////////////////////////
std::ostream &operator<<( std::ostream &lhs, const Color &rhs )
{
	switch( rhs )
	{
		case (Color::UNKNOWN_COLOR):
			lhs << "Unknown Color";
			break;
		case (Color::BLACK):
			lhs << "Black";
			break;
		case (Color::GRAY):
			lhs << "Gray";
			break;
		case (Color::BROWN):
			lhs << "Brown";
			break;
		case (Color::CREAM):
			lhs << "Cream";
			break;
		case (Color::CALICO):
			lhs << "Calico";
			break;
		case (Color::WHITE):
			lhs << "White";
			break;
		case (Color::GINGER):
			lhs << "Ginger";
			break;
		default:
			throw std::out_of_range( PROGRAM_NAME
			                         ": Color not mapped to a string!" );
	}
	return lhs;
}














