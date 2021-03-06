///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "List.h"

using namespace std;

bool List::empty() const noexcept
{
	return (_head == nullptr);
}

bool List::isIn( Node* nodeOfInterest ) const
{
	if( nodeOfInterest == nullptr )
	{
		throw invalid_argument( PROGRAM_NAME " List Error: isIn() called with nullptr argument!" );
	}

	Node* currNode = _head;
	while( currNode != nullptr )
	{
		if( currNode == nodeOfInterest )
		{
			return true; // nodeOfInterest was found
		}
		currNode = currNode->_next;
	}
	return false; // nodeOfInterest was not found
}

bool List::isSorted() const noexcept
{
	return false;
}

Node* List::get_first() const noexcept
{
	return _head;
}

Node* List::get_next( const Node* currentNode )
{
	if( currentNode == nullptr )
	{
		throw invalid_argument( PROGRAM_NAME " List Error: currentNode must not be nullptr" );
	}
	return currentNode->_next;
}

void List::deleteAllNodes() noexcept
{
	assert( validate() );
	while( _head != nullptr )
	{
		pop_front();
	}
	#ifdef DEBUG
	cout << PROGRAM_NAME << ": All Nodes have been deleted" << endl ;
	#endif
	assert( validate() );
}

unsigned long List::size() const noexcept
{
	if( _head == nullptr ) return 0;

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
