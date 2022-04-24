///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"

/////////////////////////////////// Constants ///////////////////////////////////
const std::string Animal::KINGDOM_NAME = "Animalia";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Animal::Animal( const float newMaxWeight, const std::string &newClassification, const std::string &newSpecies )
		:
		Animal( Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, newMaxWeight, newClassification, newSpecies ) {}

Animal::Animal( const Gender newGender, const float newWeight, const float newMaxWeight, const std::string &newClassification,
                const std::string &newSpecies ) : _species{ newSpecies }, _classification{ newClassification }, _gender{ newGender }
{
	_weight.setMaxWeight( newMaxWeight );
	_weight.setWeight( newWeight );
}

/////////////////////////////////// Static Methods ///////////////////////////////////
std::string Animal::gender_literal( const Gender &gender ) const
{
	std::string retStr;

	switch( gender )
	{
		case ( Gender::UNKNOWN_GENDER ):
			retStr = "Unknown Gender";
			break;
		case ( Gender::MALE ):
			retStr = "Male";
			break;
		case ( Gender::FEMALE ):
			retStr = "Female";
			break;
		default:
			retStr = "Invalid gender!";
			break;
	}
	return retStr;
}

/////////////////////////////////// Getters ///////////////////////////////////
std::string Animal::getKingdom() const noexcept
{
	return Animal::KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept
{
	return _classification;
}

std::string Animal::getSpecies() const noexcept
{
	return _species;
}

Gender Animal::getGender() const noexcept
{
	return _gender;
}

Weight Animal::getWeight() const noexcept
{
	return _weight;
}

/////////////////////////////////// Setters ///////////////////////////////////
void Animal::setWeight( const float newWeight )
{
	_weight.setWeight( newWeight );
}

void Animal::setGender( const Gender newGender )
{
	_gender = newGender;
}

/////////////////////////////////// Public Methods ///////////////////////////////////
void Animal::dump() const noexcept
{
	Node::dump();
	FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << std::endl;
	_weight.dump();
}

/////////////////////////////////// Validation Methods ///////////////////////////////////
//@todo implement validate functions
bool Animal::validateClassifaction( const std::string &checkClassification ) noexcept
{
	return false;
}

bool Animal::validate() const noexcept
{
	return false;
}

bool Animal::validateSpecies( const std::string &checkSpecies ) noexcept
{
	return false;
}

/////////////////////////////////// Operator Overloading ///////////////////////////////////
inline std::ostream &operator<<( std::ostream &lhs_stream, const Gender &rhs_Gender )
{
	switch( rhs_Gender )
	{
		case Gender::UNKNOWN_GENDER:
			lhs_stream << "Unknown gender";
			break;
		case Gender::MALE:
			lhs_stream << "Male";
			break;
		case Gender::FEMALE:
			lhs_stream << "Female";
			break;
		default:
			/// @throw out_of_range If the enum is not mapped to a string.
			throw std::out_of_range( PROGRAM_NAME
			                         ": Gender not mapped to a string!" );
	}
	return lhs_stream;
}
