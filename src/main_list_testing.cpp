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
	// Creation of SinglyLinkedList
	SinglyLinkedList tList;
	assert( tList.empty() );

	// push_front testing
	auto t1 = new Cat( "t1", Color::BLACK, false, Gender::FEMALE, 1.1 );
	tList.push_front( t1 );
	assert( tList.size() == 1 );

	tList.push_front( new Cat( "t4", Color::BROWN, false, Gender::MALE, 4.4 ) );
	assert( tList.size() == 2 );

	// insert_after testing
	auto t2 = new Cat( "t2", Color::GINGER, false, Gender::MALE, 2.2 );
	tList.insert_after( t1, t2 );
	assert( tList.size() == 3 );

	auto t3 = new Cat( "t3", Color::GINGER, false, Gender::MALE, 3.3 );
	tList.insert_after( t2, t3 );
	assert( tList.size() == 4 );

	// Make all animals in list speak
	for( Animal* pAnimal = (Animal*) tList.get_first(); pAnimal != nullptr; pAnimal = (Animal*) List::get_next( (Node*) pAnimal ) )
	{
		cout << pAnimal->speak() << endl;
	}

	//All animals in list info dump()
	cout << "dumping tList..." << endl;
	tList.dump();

	assert( tList.validate() );

	cout << "deleting all nodes" << endl;
	tList.deleteAllNodes();
	assert( tList.empty() );
	cout << "dumping empty tList" << endl;

	cout << "End of " << PROGRAM_NAME << " List Testing..." << endl;

	return (EXIT_SUCCESS);
}
