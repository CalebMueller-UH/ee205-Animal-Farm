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

#include <ostream>
#include "Animal.h"

using std::string;
using std::cout;

enum class Color
{
  UNKNOWN_COLOR = 0, BLACK, GRAY, BROWN, WHITE, CREAM, CALICO, GINGER
};

class Mammal : public Animal
{
  protected: //////////////////////////////// Member Variables ////////////////////////////////
  Color _color{Color::UNKNOWN_COLOR};

  public:  /////////////////////////////////// Constants ///////////////////////////////////
  static const string MAMMAL_NAME;

  protected:  /////////////////////////////////// Class Constructors ///////////////////////////////////
  Mammal( const t_weight newMaxWeight, const string &newSpecies );

  Mammal( const Color newColor, const Gender newGender, const t_weight newWeight, const t_weight newMaxWeight, const string newSpecies );

  public:  /////////////////////////////////// Getters ///////////////////////////////////
  Color getColor() const noexcept;

  protected:  /////////////////////////////////// Setters ///////////////////////////////////
  void setColor( const Color newColor ) noexcept;

  public:  /////////////////////////////////// Public Methods ///////////////////////////////////
  void dump() const noexcept override;
};

std::ostream &operator<<( std::ostream &lhs, const Color &rhs );

#endif //EE205_ANIMAL_FARM_MAMMAL_H
