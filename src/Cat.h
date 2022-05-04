///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date 23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H

#include <iomanip> // For print() formatting
#include <iostream> // For cout
#include <exception>  // For try/catch blocks
#include <assert.h> // For assert

#include "Mammal.h"
#include "config.h"

using std::string;
using std::cout;

class Cat : public Mammal
{
  private: //////////////////////////////// Member Variables ////////////////////////////////
  string _name;
  bool _catIsFixed;

  public:  /////////////////////////////////// Constants ///////////////////////////////////
  static const string SPECIES_NAME;
  static const Weight MAX_WEIGHT;

  public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
  Cat( const string &newName );

  Cat( const string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const t_weight newWeight );

  Cat( const string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const t_weight newWeight, const t_weight newMaxWeight );

  public:  /////////////////////////////////// Getters ///////////////////////////////////
  string getName() const noexcept;

  bool isFixed() const noexcept;

  public:  /////////////////////////////////// Setters ///////////////////////////////////
  void setName( const string &newName );

  void fixCat() noexcept;

  public:  /////////////////////////////////// Public Methods ///////////////////////////////////
  string speak() const noexcept override;

  void dump() const noexcept override;

  public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
  bool validate() const noexcept override;

  static bool nameIsValid( const string &newName );
}; // End of Cat class

#endif //EE205_ANIMAL_FARM_CAT_H
