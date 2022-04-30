///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_LIST_H
#define EE205_ANIMAL_FARM_LIST_H

#include <exception>
#include <iostream>
#include <cassert>

#include "config.h"
#include "Node.h"

using namespace std;

class List
{
  protected: //////////////////////////////// Member Variables ////////////////////////////////
  Node* _head{nullptr};
  unsigned long _count{0};

  public:  /////////////////////////////////// Public Methods ///////////////////////////////////
  bool empty() const noexcept;

  bool isIn( Node* nodeOfInterest ) const;

  bool isSorted() const noexcept;

  Node* get_first() const noexcept;

  static Node* get_next( const Node* currentNode );

  void deleteAllNodes() noexcept;

  unsigned long size() const noexcept;

  public:  /////////////////////////////////// Virtual Methods ///////////////////////////////////

  virtual Node* pop_front() noexcept = 0;

  virtual void dump() const noexcept = 0;

  virtual bool validate() const noexcept = 0;
};

#endif //EE205_ANIMAL_FARM_LIST_H
