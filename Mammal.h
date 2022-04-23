///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   20_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_MAMMAL_H
#define EE205_ANIMAL_FARM_MAMMAL_H

#include "Animal.h"

enum class Color
{
	UNKNOWN_COLOR,
	BLACK,
	GREY,
	BROWN,
	TAN,
	ORANGE
};

class Mammal : public Animal
{
private: //////////////////////////////// Member Variables ////////////////////////////////
	Color _color;

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const std::string MAMMAL_NAME;

public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	Mammal( const Weight newMaxWeight, const std::string &newSpecies );

	Mammal( const Color newColor, const Gender newGender, const Weight newWeight, const Weight newMaxWeight, const std::string newSpecies );

public:  /////////////////////////////////// Getters ///////////////////////////////////
	Color getColor() const noexcept;

public:  /////////////////////////////////// Setters ///////////////////////////////////
	void setColor( const Color newColor ) noexcept;


public:  /////////////////////////////////// Public Methods ///////////////////////////////////
	void dump() const noexcept override;

};


#endif //EE205_ANIMAL_FARM_MAMMAL_H
