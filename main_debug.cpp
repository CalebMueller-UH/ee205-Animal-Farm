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

int main()
{
    std::cout << "Starting " << PROGRAM_NAME << std::endl;
    std::cout << "==================================================\n" << endl;

    // Test routine
    {
        int testNum = 0;
        // >>>>>>>>>>>>>>>>>>>>>>>>>  Default Constructor Value Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tConstructing a cat with default constructor and\n\t"
                                            "checking for proper default member variable assignment...\n";
        Cat *defaultCat = new Cat();
        assert(strcmp(defaultCat->getName(), "") == 0);
        assert(defaultCat->getName() != nullptr);
        assert(defaultCat->getGender() == UNKNOWN_GENDER);
        assert(defaultCat->getBreed() == UNKNOWN_BREED);
        assert(!defaultCat->isCatFixed());
        assert(!defaultCat->validate());

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        try {
            cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set _name to nullptr...\n";
            defaultCat->setName(nullptr);
            assert(false);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set _name to empty string (\"\")...\n";
        try {
            defaultCat->setName("");
            assert(false);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set name to a single character...\n";
        defaultCat->setName("D");
        assert(strcmp(defaultCat->getName(), "D") == 0);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set name to a name with MAX_NAME_LEN...\n";
        char MAX_NAME1[MAX_NAME_LEN];
        memset(MAX_NAME1, 'A', MAX_NAME_LEN);
        defaultCat->setName(MAX_NAME1);
        assert(strcmp(defaultCat->getName(), MAX_NAME1) == 0);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting setName() with too long of a name...\n";
        try {
            char ILLEGAL_NAME[MAX_NAME_LEN + 1];
            memset(ILLEGAL_NAME, 'A', MAX_NAME_LEN + 1);
            defaultCat->setName(ILLEGAL_NAME);
            assert(strcmp(defaultCat->getName(), ILLEGAL_NAME) != 0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setGender() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // @todo Change test once administrative management object is implemented
        cout << "\n>>Test " << testNum++ << ": \n\tTesting setGender...\n";
        defaultCat->setGender(MALE);
        assert(defaultCat->getGender() == MALE);
        defaultCat->setGender(FEMALE);
        assert(defaultCat->getGender() != FEMALE);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setBreed() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // @todo Change test once administrative management object is implemented
        cout << "\n>>Test " << testNum++ << ": \n\tTesting setBreed()...\n";
        defaultCat->setBreed(MANX);
        assert(defaultCat->getBreed() != UNKNOWN_BREED);
        defaultCat->setBreed(SHORTHAIR);
        assert(defaultCat->getBreed() != SHORTHAIR);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  fixCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting fixCat()...\n";
        assert(!defaultCat->isCatFixed());
        defaultCat->fixCat();
        assert(defaultCat->isCatFixed());
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set _weight to an invalid value less than 0...\n";
        try {
            defaultCat->setWeight(-5.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set _weight to an invalid value of 0...\n";
        try {
            defaultCat->setWeight(0.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++
             << ": \n\tAttempting to set _weight to an invalid value greater than MAX_CAT_WEIGHT...\n";
        try {
            defaultCat->setWeight(MAX_CAT_WEIGHT + 1.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to set _weight to a valid decimal value...\n";
        defaultCat->setWeight(1 / (float) 1024);
        assert(defaultCat->getWeight() == 1 / (float) 1024);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  validate() and print() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting print() method of Cat class\n";
        assert(defaultCat->validate());
        assert(defaultCat->print());

        // >>>>>>>>>>>>>>>>>>>>>>>>>  addCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting implicit addCat by passing in an already existing dynamic Cat object...\n";
        Cat *dynamo = new Cat("Dynamo", MALE, PERSIAN, 6.00);
        assert(addCat(dynamo));
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  addCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tAttempting to add the same dynamic Cat object again; this should throw an error...\n";
        try
        {
            assert(!addCat(dynamo));
        }
        catch(const std::exception &e)
        {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  validateDatabase() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting validateDatabase()...\n";
        assert(validateDatabase());
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  deleteCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting deleteCat...\n";
        { // deleteCat() Test Scope
            Cat *a = new Cat("A", MALE, MAINE_COON, 5);
            Cat *b = new Cat("B", MALE, MAINE_COON, 5);
            Cat *c = new Cat("C", MALE, MAINE_COON, 5);
            addCat(a);
            addCat(b);
            addCat(c);
            // Delete Middle In List
            assert(deleteCat(b));
            assert(!deleteCat(b));
            // Delete First In List
            assert(deleteCat(c));
            assert(!deleteCat(c));
            // Delete Last In List
            assert(deleteCat(a));
            assert(!deleteCat(a));
            cout << " pass." << endl;
        } // End of deleteCat() Test Scope

        // >>>>>>>>>>>>>>>>>>>>>>>>>  printAllCats() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting printAllCats(), by iterating over some added cats...\n";
        { // printAllCats() Test Scope
            Cat *a = new Cat("A", MALE, MAINE_COON, 5);
            Cat *b = new Cat("B", MALE, MAINE_COON, 5);
            Cat *c = new Cat("C", MALE, MAINE_COON, 5);
            addCat(a);
            addCat(b);
            addCat(c);
            assert(printAllCats());

            // >>>>>>>>>>>>>>>>>>>>>>>>>  deleteAllCats() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            cout << "\n>>Test " << testNum++ << ": \n\tTesting deleteAllCats()...\n";
            deleteAllCats();
            printAllCats();
            assert(catListHead == nullptr);
            assert(findCatByName("A") == nullptr);
            assert(findCatByName("B") == nullptr);
            assert(findCatByName("C") == nullptr);
            assert(!catIsInDatabase(a));
            assert(!catIsInDatabase(b));
            assert(!catIsInDatabase(c));
            cout << " pass." << endl;
        } // End of printAllCats() Test Scope

        // >>>>>>>>>>>>>>>>>>>>>>>>>  findCatByName() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        { // findCatByName() Test Scope
            cout << "\n>>Test " << testNum++ << ": \n\tTesting findCatByName...\n";
            Cat *z = new Cat("Z", MALE, MAINE_COON, 5);
            addCat(z);
            assert(findCatByName("Z") == z);
            assert(findCatByName("Mario") == nullptr);
            cout << " pass." << endl;
            deleteAllCats();
        } // End of findCatByName() Test Scope

        // >>>>>>>>>>>>>>>>>>>>>>>>>  genderLiteral() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting genderLiteral()...\n";
        assert(strcmp(genderLiteral(UNKNOWN_GENDER), "UNKNOWN_GENDER") == 0);
        assert(strcmp(genderLiteral(MALE), "MALE") == 0);
        assert(strcmp(genderLiteral(FEMALE), "FEMALE") == 0);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  breedLiteral() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "\n>>Test " << testNum++ << ": \n\tTesting breedLiteral()...\n";
        assert(strcmp(breedLiteral(UNKNOWN_BREED), "UNKNOWN_BREED") == 0);
        assert(strcmp(breedLiteral(MAINE_COON), "MAINE_COON") == 0);
        assert(strcmp(breedLiteral(MANX), "MANX") == 0);
        assert(strcmp(breedLiteral(SHORTHAIR), "SHORTHAIR") == 0);
        assert(strcmp(breedLiteral(PERSIAN), "PERSIAN") == 0);
        assert(strcmp(breedLiteral(SPHYNX), "SPHYNX") == 0);
        cout << " pass." << endl;

        cout << "\nEnd of Testing Routine... All tests passed!" << endl;
    }   // End of Test routine

    std::cout << "\n==================================================" << endl;
    std::cout << "Done with " << PROGRAM_NAME << std::endl;

    return 0;
}
