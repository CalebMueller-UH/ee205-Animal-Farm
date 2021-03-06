///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date 23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_NODE_H
#define EE205_ANIMAL_FARM_NODE_H

#include <iostream>
#include <string>

#include "config.h"

class Node
{
  friend class SinglyLinkedList;

  friend class List;

  protected: //////////////////////////////// Member Variables ////////////////////////////////
  Node* _next{nullptr};

  public:  /////////////////////////////////// Virtual Methods ///////////////////////////////////
  virtual void dump() const;

  virtual bool operator>( const Node &rhs );

  public:  /////////////////////////////////// Public Methods ///////////////////////////////////
  static bool compareByAddress( const Node* node1, const Node* node2 );

  public:  /////////////////////////////////// Validation Methods ///////////////////////////////////
  virtual bool validate() const noexcept;
};

#endif //EE205_ANIMAL_FARM_NODE_H
