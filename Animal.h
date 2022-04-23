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

#include "Node.h"
#include "Weight.h"


/////////////////////////////////// Enumerations ///////////////////////////////////
enum class Gender
{
	UNKNOWN_GENDER,
	MALE,
	FEMALE
};


class Animal : public Node
{

private: //////////////////////////////// Member Variables ////////////////////////////////
	std::string _species;
	std::string _classification;
	Gender _gender;
	Weight _weight;

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const std::string KINGDOM_NAME;

public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	Animal( const Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );

	Animal( const Gender newGender, const Weight newWeight, const Weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );

public:  /////////////////////////////////// Getters ///////////////////////////////////
	std::string getKingdom() const noexcept;

	std::string getClassification() const noexcept;

	std::string getSpecies() const noexcept;

	Gender getGender() const noexcept;

	Weight getWeight() const noexcept;

public:  /////////////////////////////////// Setters ///////////////////////////////////

	void setWeight( const Weight newWeight );

	void setGender( const Gender newGender );

public:  /////////////////////////////////// Public Methods ///////////////////////////////////
	virtual std::string speak() const noexcept = 0;

	void dump() const noexcept override;

public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
	bool validate() const noexcept override;

	static bool validateClassifaction( const std::string &checkClassification ) noexcept;

	static bool validateSpecies( const std::string &checkSpecies ) noexcept;

};


#endif //EE205_ANIMAL_FARM_ANIMAL_H
