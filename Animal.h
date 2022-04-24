///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H

#include <ostream>
#include <string.h>

#include "config.h"
#include "Node.h"
#include "Weight.h"

enum class Gender
{
	UNKNOWN_GENDER = 0,
	MALE,
	FEMALE
};

inline std::ostream &operator<<( std::ostream &lhs_stream, const Gender &rhs_Gender );


class Animal : public Node
{

protected: //////////////////////////////// Member Variables ////////////////////////////////
	std::string _species;
	std::string _classification;
	Gender _gender;
	Weight _weight;

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const std::string KINGDOM_NAME;

protected:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	Animal( const float newMaxWeight, const std::string &newClassification, const std::string &newSpecies );

	Animal( const Gender newGender, const float newWeight, const float newMaxWeight, const std::string &newClassification,
	        const std::string &newSpecies );

public:  /////////////////////////////////// Static Methods ///////////////////////////////////
std::string gender_literal(const Gender& gender) const;

public:  /////////////////////////////////// Getters ///////////////////////////////////
	std::string getKingdom() const noexcept;

	std::string getClassification() const noexcept;

	std::string getSpecies() const noexcept;

	Gender getGender() const noexcept;

	Weight getWeight() const noexcept;

protected:  /////////////////////////////////// Setters ///////////////////////////////////

	void setWeight( const float newWeight );

	void setGender( const Gender newGender );

protected:  /////////////////////////////////// Methods ///////////////////////////////////
	virtual std::string speak() const noexcept = 0;

	void dump() const noexcept override;

public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
	bool validate() const noexcept override;

	static bool validateClassifaction( const std::string &checkClassification ) noexcept;

	static bool validateSpecies( const std::string &checkSpecies ) noexcept;

};

#endif //EE205_ANIMAL_FARM_ANIMAL_H