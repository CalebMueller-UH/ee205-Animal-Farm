///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date 23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H

#include <ostream>
#include <string.h>

#include "config.h"
#include "Node.h"
#include "Weight.h"

using std::ostream;
using std::string;
using std::cout;

enum class Gender {
  UNKNOWN_GENDER = 0,
  MALE,
  FEMALE
};

inline ostream& operator<<(ostream& lhs_stream, const Gender& rhs_Gender);

class Animal : public Node {
protected: //////////////////////////////// Member Variables ////////////////////////////////
	string _species;
	string _classification;
	Gender _gender{Gender::UNKNOWN_GENDER};
	Weight _weight{Weight::UNKNOWN_WEIGHT};

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const string KINGDOM_NAME;

protected:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	Animal(const t_weight newMaxWeight, const string& newClassification, const string& newSpecies);

	Animal(const Gender newGender, const t_weight newWeight, const t_weight newMaxWeight, const string& newClassification,
			const string& newSpecies);

public:  /////////////////////////////////// Static Methods ///////////////////////////////////
	string getGenderLiteral(const Gender& gender) const;

public:  /////////////////////////////////// Getters ///////////////////////////////////
	string getKingdom() const noexcept;

	string getClassification() const noexcept;

	string getSpecies() const noexcept;

	Gender getGender() const noexcept;

	Weight getWeight() const noexcept;

protected:  /////////////////////////////////// Setters ///////////////////////////////////

	void setWeight(const t_weight newWeight);

	void setGender(const Gender newGender);

public:  /////////////////////////////////// Public Virtual Methods ///////////////////////////////////
	virtual string speak() const noexcept = 0;

public:  /////////////////////////////////// Public Methods ///////////////////////////////////
	void dump() const noexcept override;

public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
	static bool validateClassifaction(const string& checkClassification) noexcept;

	static bool validateSpecies(const string& checkSpecies) noexcept;

	bool validate() const noexcept override;

};

#endif //EE205_ANIMAL_FARM_ANIMAL_H