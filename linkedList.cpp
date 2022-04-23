///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file linkedList.cpp
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   04_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "linkedList.h"

bool addCat( Cat *newCat )
{
	// No invalid Cat shall pass!
	if( !validateDatabase())
	{
		return false;
	}

	// Critical error should end program
	assert( newCat != nullptr );
	newCat->validate();

	if( catIsInDatabase( newCat ))
	{
		throw logic_error( PROGRAM_NAME " addCat Error: Cat is already in database!" );
	}

	newCat->_next = catListHead;
	catListHead = newCat;

	if( !validateDatabase())
	{
		return false;
	}
	return true;
} // End of addCat()

bool catIsInDatabase( Cat *tCat )
{
	Cat *curCat = catListHead;
	while( curCat != nullptr )
	{
		if( tCat == curCat )
		{
			return true; // cat already exists in database
		}
		curCat = curCat->_next;
	}
	return false; // tCat is a pointer address not found elsewhere in the linked list
} // End of catIsInDatabase()

bool validateDatabase()
{
	Cat *currCat = catListHead;
	while( currCat != nullptr )
	{
		if( !currCat->validate())
		{
			return false; // Cat object containing invalid entry found!
		}
		currCat = currCat->_next;
	}
	return true; // Everything checks out
} // End of validateDatabase()

bool deleteCat( Cat *deleteThisCat )
{
	// No invalid Cat shall pass!
	if( !validateDatabase())
	{
		return false;
	}

	Cat *prevCat = nullptr;
	Cat *currCat = catListHead;

	while( currCat != nullptr )
	{
		if( currCat == deleteThisCat )
		{
			// Check for special case where deleteThisCat is the head item in the list
			if( prevCat == nullptr )
			{
				catListHead = currCat->_next;
				delete currCat;
				return true; //
			}

			// Found the cat to be deleted, and isn't head of list
			// Splice out and delete
			prevCat->_next = currCat->_next;
			delete currCat;

			// No invalid Cat shall pass!
			if( !validateDatabase())
			{
				return false;
			}
			return true;  // Target found and eliminated, rtb
		}
		// currCat is not the Cat we're looking for, iterate to next link in list
		prevCat = currCat;
		currCat = currCat->_next;
	}
	return false; // Was not able to find specified Cat object to delete
} // End of deleteCat()

bool deleteAllCats()
{
	// No invalid Cat shall pass!
	if( !validateDatabase())
	{
		return false;
	}
	Cat *currCat = catListHead;

	while( catListHead != nullptr )
	{
		currCat = catListHead;
		catListHead = currCat->_next;
		delete currCat;
	}

	// No invalid Cat shall pass!
	if( !validateDatabase())
	{
		return false;
	}
	return true; // All Cat objects within the linked list have successfully been removed
} // End of deleteAllCats()

bool printAllCats()
{
	Cat *currCat = catListHead;

	while( currCat != nullptr )
	{
		if( !currCat->print())
		{
			return false;
		}
		currCat = currCat->_next;
	}
	return true;
} // End of printAllCats()

Cat *findCatByName( const char *testName )
{
	Cat *currCat = catListHead;

	while( currCat != nullptr )
	{
		if( strcmp( currCat->getName(), testName ) == 0 )
		{
			return currCat;
		}
		currCat = currCat->_next;
	}
	return nullptr;
} // End of findCatByName


