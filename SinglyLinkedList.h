///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_SINGLYLINKEDLIST_H
#define EE205_ANIMAL_FARM_SINGLYLINKEDLIST_H

//#include <exception>
//#include <iostream>

#include "config.h"
#include "List.h"
#include "Node.h"

using namespace std;

class SinglyLinkedList : public List
{
//public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
//	SinglyLinkedList();

public:  /////////////////////////////////// Public Methods ///////////////////////////////////
	void push_front( Node *newNode );

	Node *pop_front() noexcept override;

	bool insert_after( Node *insertAfterNode, Node *nodeToBeInserted );

	void dump() const noexcept override;

	bool validate() const noexcept override;
};


#endif //EE205_ANIMAL_FARM_SINGLYLINKEDLIST_H
