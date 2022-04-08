///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file main.c
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   16_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream> // For cout
#include <exception> // For try/catch blocks
#include <cstdlib> // For EXIT_SUCCESS and EXIT_FAILURE
#include <assert.h> // For assert()
#include <string.h>

#include "config.h"
#include "Cat.h"
#include "catDatabase.h"
#include "linkedList.h"

using namespace std;

int main() {
    std::cout << "Starting " << PROGRAM_NAME << std::endl;
    std::cout << "==================================================\n" << endl;

    // Release Code
    {
        cout << "\nBeginning Release Code..." << endl;
        Cat *loki = new Cat("Loki", MALE, PERSIAN, 1.0);
        Cat *milo = new Cat("Milo", FEMALE, MANX, 1.1);
        Cat *bella = new Cat("Bella", FEMALE, MAINE_COON, 1.2);
        Cat *kali = new Cat("Kali", FEMALE, SHORTHAIR, 1.3);
        Cat *trin = new Cat("Trin", FEMALE, MANX, 1.4);
        Cat *chili = new Cat("Chili", MALE, SHORTHAIR, 1.5);

        addCat(loki);
        addCat(milo);
        addCat(bella);
        addCat(kali);
        addCat(trin);
        addCat(chili);

        printAllCats();
        deleteAllCats();
        printAllCats();

        cout << "End of Release Code..." << endl;
    }
    // End of Release Code

    std::cout << "\n==================================================" << endl;
    std::cout << "Done with " << PROGRAM_NAME << std::endl;

    return 0;
}
