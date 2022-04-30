///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file main_list_testing.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include <string>
#include <assert.h>

#include "Cat.h"
#include "SinglyLinkedList.h"

using std::string;
using std::cout;

int main()
{
	cout << "Starting " << PROGRAM_NAME << " List Testing..." << endl;

	// SinglyLinkedList Class Method Testing

	{
		// Creation of SinglyLinkedList
		SinglyLinkedList tList;

		// Pushing initial object into list
		auto t1 = new Cat( "t1", Color::BLACK, false, Gender::FEMALE, 25 );
		tList.push_front( t1 );
		assert( tList.size() == 1 );

		auto t2 = new Cat( "t2", Color::GINGER, false, Gender::MALE, 14 );
		tList.insert_after( t1, t2 );
		assert( tList.size() == 2 );

		assert( tList.pop_front() == t1 );

		for( Animal* pAnimal = (Animal*) tList.get_first(); pAnimal != nullptr; pAnimal = (Animal*) List::get_next( (Node*) pAnimal ) )
		{
			cout << pAnimal->speak() << endl;
		}
	} // End of SinglyLinkedList Testing

	/*
	catDB.validate();
	catDB.dump();
	catDB.deleteAllNodes();
	catDB.dump();
	cout << "Done with " << PROGRAM_NAME;
	 */
	return (EXIT_SUCCESS);

	return 0;
}
