///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "SinglyLinkedList.h"

void SinglyLinkedList::push_front( Node* newNode )
{
	if( newNode == nullptr)
	{
		return;
	}

	if( newNode->validate() )
	{
		newNode->_next = _head;
		_head = newNode;
		_count++;
	}
}

Node* SinglyLinkedList::pop_front()

noexcept
{
	Node* front = _head;

	_head = _head->_next;

	front->

			_next = nullptr;

	_count--;
	return

			front;
}

bool SinglyLinkedList::insert_after( Node* insertAfterNode, Node* nodeToBeInserted )
{
	/////////////////// Argument Checking /////////////////////////
	if( insertAfterNode == nullptr )
	{
		throw invalid_argument( PROGRAM_NAME "SinglyLinkedList Error: insert_after() was called with the a null insertAfterNode memory address!" );
	}
	if( nodeToBeInserted == nullptr )
	{
		throw invalid_argument( PROGRAM_NAME "SinglyLinkedList Error: insert_after() was called with the a null nodeToBeInserted memory address!" );
	}
	if( !nodeToBeInserted->validate() )
	{
		throw invalid_argument( PROGRAM_NAME "SinglyLinkedList Error: insert_after() was called with the an invalid nodeToBeInserted Node!" );
	}

	/////////////////// Empty List Checking /////////////////////////
	if( _head == nullptr )
	{
		throw logic_error( PROGRAM_NAME "SinglyLinkedList Error: insert_after() can not be called on an empty list!" );
	}

	/////////////////// Do The Thing  /////////////////////////
	Node* currNode = _head; // currNode iterates through linked list
	// Find insertion point
	while( currNode != nullptr )
	{
		if( currNode == insertAfterNode )
		{
			// Splice in
			nodeToBeInserted->_next = currNode->_next;
			currNode->_next = nodeToBeInserted;
			_count++;
			return true; // operation was successful
		}
		currNode = currNode->_next; // iterate through list
	}
	// if thread reaches this point then insertAfterNode wasn't found in the while loop
	throw logic_error( PROGRAM_NAME "SinglyLinkedList Error: insert_after() insertAfterNode not Found!" );
}


// End of insert_after()

void SinglyLinkedList::dump() const

noexcept
{
	cout << "SinglyLinkeList head=[ " << this->

			get_first()

	     << " ]" <<

	     std::endl;

	Node* currentNode = _head;

	while( currentNode != nullptr )
	{
		currentNode->

				dump();

		currentNode = currentNode->_next;
	}
}

unsigned long SinglyLinkedList::size() const noexcept
{
	Node* currentNode = _head;
	unsigned long size_count = 0;

	do
	{
		size_count++;
		currentNode = currentNode->_next;
	}
	while( currentNode != nullptr );

	return size_count;
}

bool SinglyLinkedList::validate() const noexcept
{
// Check for empty list
	if( _count == 0 )
	{
		assert( this->empty() );
		assert( this->size() == 0 );
	}
// Check for single element list
	if( _count == 1 )
	{
		assert( _head->_next == nullptr );
		assert( this->size() == 1 );
	}

	if( _count > 1 )
	{
		assert( this->size() == _count );
	}
	return true; // Valid list returns true
}


