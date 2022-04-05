///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file main.c
/// @version 1.0
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

    // Test routine
#ifdef DEBUG_ENABLE
    {
        //
        cout << "Test 1: \n\tConstructing a cat with default constructor and checking for\n\t"
                "proper default member variable assignment...\n";
        Cat *defaultCat = new Cat();
        assert(strcmp(defaultCat->getName(), "") == 0);
        assert(defaultCat->getName() != nullptr);
        assert(defaultCat->getGender() == UNKNOWN_GENDER);
        assert(defaultCat->getBreed() == UNKNOWN_BREED);
        assert(!defaultCat->isCatFixed());
        assert(!defaultCat->validate());

        // >>>>>>>>>>>>>>>>>>>>>>>>>  Name Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        try {
            cout << "Test 2: \n\tAttempting to set _name to nullptr...\n";
            defaultCat->setName(nullptr);
            assert(false);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 3: \n\tAttempting to set _name to empty string (\"\")...\n";
        try {
            defaultCat->setName("");
            assert(false);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 4: \n\tAttempting to set name to lower valid boundary condition...";
        defaultCat->setName("D");
        assert(strcmp(defaultCat->getName(), "D") == 0);
        cout << " pass." << endl;

        //
        cout << "Test 5: \n\tAttempting to set name to a name with (MAX_NAME_LEN -1)...";
        char MAX_NAME1[MAX_NAME_LEN];
        memset(MAX_NAME1, 'A', MAX_NAME_LEN-1);
        defaultCat->setName(MAX_NAME1);
        assert(strcmp(defaultCat->getName(), MAX_NAME1) == 0);
        cout << " pass." << endl;

        //
        cout << "Test 6: \n\tTesting setName() with too long of a name...\n";
        try {
            char ILLEGAL_NAME[MAX_NAME_LEN + 1];
            memset(ILLEGAL_NAME, 'A', MAX_NAME_LEN+1);
            defaultCat->setName(ILLEGAL_NAME);
            assert(strcmp(defaultCat->getName(), ILLEGAL_NAME) != 0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setGender() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // @todo Change test once administrative management object is implemented
        cout << "Test 7: \n\tTesting setGender...";
        defaultCat->setGender(MALE);
        assert(defaultCat->getGender() == MALE);
        defaultCat->setGender(FEMALE);
        assert(defaultCat->getGender() != FEMALE);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setBreed() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // @todo Change test once administrative management object is implemented
        cout << "Test 8: \n\tTesting setBreed()...";
        defaultCat->setBreed(MANX);
        assert(defaultCat->getBreed() != UNKNOWN_BREED);
        defaultCat->setBreed(SHORTHAIR);
        assert(defaultCat->getBreed() != SHORTHAIR);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  fixCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "Test 9: \n\tTesting fixCat()...";
        assert(!defaultCat->isCatFixed());
        defaultCat->fixCat();
        assert(defaultCat->isCatFixed());
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "Test 10: \n\tAttempting to set _weight to an invalid value less than 0...";
        try {
            defaultCat->setWeight(-5.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 11: \n\tAttempting to set _weight to an invalid value of 0...";
        try {
            defaultCat->setWeight(0.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 12: \n\tAttempting to set _weight to an invalid value greater than MAX_CAT_WEIGHT...";
        try {
            defaultCat->setWeight(MAX_CAT_WEIGHT + 1.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 13: \n\tAttempting to set _weight to a valid decimal value...";
        defaultCat->setWeight(1/(float)1024);
        assert(defaultCat->getWeight() ==  1/(float)1024);
        cout << " pass." << endl;

        // All member variables have been assigned valid entries
        // validate() should now yield success
        cout << "Test 14: \n\tTesting print() method of Cat class\n";
        assert(defaultCat->validate());
        defaultCat->print();

        //
        cout << "\nTest 15: \n\tTesting zeroize() for destructor to see if parameter fields properly set to specified values...";
        defaultCat->zeroize();
        char zeroName[MAX_NAME_LEN];
        memset(zeroName, '0', MAX_NAME_LEN);
        assert(strcmp(defaultCat->getName(), zeroName) == 0);
        assert(defaultCat->getGender() == UNKNOWN_GENDER);
        assert(defaultCat->getBreed() == UNKNOWN_BREED);
        assert(!defaultCat->isCatFixed());
        assert(defaultCat->getWeight() == UNKNOWN_WEIGHT);
        cout << " pass." << endl;

        //
        cout << "Test 16: \n\tTesting implicit addCat by passing in an already existing dynamic Cat object...";
        Cat *dynamo = new Cat("Dynamo", MALE, PERSIAN, 6.00);
        assert(addCat(dynamo));
        cout << " pass." << endl;

        //
        cout << "Test 17: \n\tAttempting to add the same dynamic Cat object again; this should throw an error...\n";
        try
        {
            assert(!addCat(dynamo));
        }
        catch(const std::exception &e)
        {
            cout << e.what() << endl;
        }

        //
        cout << "Test 18: \n\tTesting validateDatabase()...";
        assert(validateDatabase());
        cout << " pass." << endl;

        //
        cout << "Test 19: \n\tAttempting to validateDatabase() after manually setting a parameter to an invalid value...\n";
        dynamo->zeroize();
        try {
            assert(!validateDatabase());
        }catch(const std::exception &e){
            cout << e.what() << endl;
        }

        //
        cout << "Test 20: \n\tTesting deleteCat...";
        assert(deleteCat(dynamo));
        assert(!deleteCat(dynamo));
        cout << " pass." << endl;

        //
        cout << "Test 21: \n\tTesting printAllCats(), by iterating over some added cats..." << endl;
        {
            Cat *a = new Cat("A", MALE, MAINE_COON, 5);
            Cat *b = new Cat("B", MALE, MAINE_COON, 5);
            Cat *c = new Cat("C", MALE, MAINE_COON, 5);
            addCat(a);
            addCat(b);
            addCat(c);
        printAllCats();

        //
        cout << "Test 22: \n\tTesting deleteCat again on the b object and verifying that it has been propertly removed...";
        assert(deleteCat(b));
        printAllCats();

        //
        cout << "\nTest 23: \n\tTesting deleteAllCats()...";
        deleteAllCats();
        printAllCats();
        assert(catListHead == nullptr);
        cout << " pass." << endl;
        }

        {
            //
            cout << "Test 24: \n\tTesting findCatByName...";
            Cat *z = new Cat("Z", MALE, MAINE_COON, 5);
            addCat(z);
            assert(findCatByName("Z") == z);
            assert(findCatByName("Mario") == nullptr);
            cout << " pass." << endl;
            deleteAllCats();
        }

        // genderLiteral testing
        assert(strcmp(genderLiteral(UNKNOWN_GENDER), "UNKNOWN_GENDER") == 0);
        assert(strcmp(genderLiteral(MALE), "MALE") == 0);
        assert(strcmp(genderLiteral(FEMALE), "FEMALE") == 0);

        // breedLiteral testing
        assert(strcmp(breedLiteral(UNKNOWN_BREED), "UNKNOWN_BREED") == 0);
        assert(strcmp(breedLiteral(MAINE_COON), "MAINE_COON") == 0);
        assert(strcmp(breedLiteral(MANX), "MANX") == 0);
        assert(strcmp(breedLiteral(SHORTHAIR), "SHORTHAIR") == 0);
        assert(strcmp(breedLiteral(PERSIAN), "PERSIAN") == 0);
        assert(strcmp(breedLiteral(SPHYNX), "SPHYNX") == 0);
    }
#endif
    // End of Test routine

    // Release Code
    Cat *loki = new Cat("Loki",  MALE,  PERSIAN,  1.0);
    Cat *milo = new Cat("Milo",  FEMALE,  MANX,  1.1);
    Cat *bella = new Cat("Bella",  FEMALE,  MAINE_COON,  1.2);
    Cat *kali = new Cat("Kali",  FEMALE,  SHORTHAIR,  1.3);
    Cat *trin = new Cat("Trin",  FEMALE,  MANX,  1.4);
    Cat *chili = new Cat("Chili",  MALE,  SHORTHAIR,  1.5);

    addCat(loki);
    addCat(milo);
    addCat(bella);
    addCat(kali);
    addCat(trin);
    addCat(chili);

    printAllCats();
    deleteAllCats();
    printAllCats();
    // End of Release Code

    std::cout << "\n==================================================" << endl;
    std::cout << "Done with " << PROGRAM_NAME << std::endl;

    return 0;
}
