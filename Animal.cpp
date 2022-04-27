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

using std::string;

/////////////////////////////////// Constants ///////////////////////////////////
const string Animal::KINGDOM_NAME = "Animalia";

/////////////////////////////////// Class Constructors ///////////////////////////////////
Animal::Animal( const t_weight newMaxWeight,
				const string &newClassification,
				const string &newSpecies )
				:
				Animal( Gender::UNKNOWN_GENDER, Weight::UNKNOWN_WEIGHT, newMaxWeight, newClassification, newSpecies)
				{}

Animal::Animal( const Gender newGender,
				const t_weight newWeight,
				const t_weight newMaxWeight,
				const string &newClassification,
				const  string &newSpecies )
				:
				_species{ newSpecies }, _classification{ newClassification }, _gender{ newGender }
				{
				_weight.setMaxWeight( newMaxWeight );
				_weight.setWeight( newWeight );
				}

/////////////////////////////////// Static Methods ///////////////////////////////////
string Animal::getGenderLiteral( const Gender &gender ) const
{
	string retStr;
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
string Animal::getKingdom() const noexcept
{
	return Animal::KINGDOM_NAME;
}

string Animal::getClassification() const noexcept
{
	return _classification;
}

string Animal::getSpecies() const noexcept
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
void Animal::setWeight( const t_weight newWeight )
{
	if( Weight::weightIsValid( newWeight, _weight.getMaxWeight()))
	{
		_weight.setWeight( newWeight );
	}
}

void Animal::setGender( const Gender newGender )
{
	if( newGender == Gender::UNKNOWN_GENDER )
	{
		_gender = newGender;
	}
	cout << PROGRAM_NAME "Animal Error: Gender is already assigned!" << std::endl;
}

/////////////////////////////////// Methods ///////////////////////////////////
void Animal::dump() const noexcept
{
	Node::dump();
	FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << std::endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << _weight << std::endl;
}

/////////////////////////////////// Validation Methods ///////////////////////////////////
bool Animal::validateClassifaction( const string &checkClassification ) noexcept
{
	if( checkClassification.empty())
	{
		cout << PROGRAM_NAME " Animal Validation Error: Classification is empty!" <<
		std::endl;
		return false;
	}
	return true; // classification is valid
}

bool Animal::validateSpecies( const string &checkSpecies ) noexcept
{
	if( checkSpecies.empty())
	{
		cout << PROGRAM_NAME " Animal Validation Error: Species is empty!" << std::endl;
		return false;
	}
	return true; // species is valid}
}

bool Animal::validate() const noexcept
{
	Node::validate();
	assert( validateClassifaction( getClassification()));
	assert( validateSpecies( getSpecies()));
	assert( _weight.validate());
	return true; // everything checks out
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
			throw std::out_of_range( PROGRAM_NAME
			                         ": Gender not mapped to a string!" );
	}
	return lhs_stream;
}
