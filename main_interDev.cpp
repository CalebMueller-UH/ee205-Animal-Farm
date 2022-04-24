///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file main_interDev.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include <assert.h>

#include "Node.h"
#include "Animal.h"
#include "Mammal.h"
#include "Cat.h"
#include "Weight.h"

using namespace std;

int main()
{
	cout << "Beginning " << PROGRAM_NAME << " testing..." << endl;

	//Constructing a new Cat and testing contents
	{
		Cat* newCat = new Cat("Newcat" , Color::ORANGE, false, Gender::FEMALE, 10.0F, 50.0F);
		newCat->dump();
	}
}
