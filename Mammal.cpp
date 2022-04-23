///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

/////////////////////////////////// Constants ///////////////////////////////////
static const std::string MAMMAL_NAME = "Mammalia";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Mammal::Mammal( const float newMaxWeight, const std::string &newSpecies )
		:
		Mammal( Color::UNKNOWN_COLOR, Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, newMaxWeight, newSpecies ) {}

Mammal::Mammal( const Color newColor, const Gender newGender, const float newWeight, const float newMaxWeight, const std::string newSpecies )
		:
		Animal(newGender, newWeight, newMaxWeight, Mammal::MAMMAL_NAME, newSpecies ), _color{ newColor } {}

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
}














