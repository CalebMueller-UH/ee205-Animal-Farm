///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Node.h"

/////////////////////////////////// Virtual Methods ///////////////////////////////////
void Node::dump() const
{
	FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl;
	FORMAT_LINE_FOR_DUMP( "Node", "next" ) << _next << std::endl;
}

bool Node::operator>( const Node &rhs )
{
	return compareByAddress( this, &( Node & ) rhs );
}

/////////////////////////////////// Public Methods ///////////////////////////////////
bool Node::compareByAddress( const Node *node1, const Node *node2 )
{
	return node1 == node2;
}
