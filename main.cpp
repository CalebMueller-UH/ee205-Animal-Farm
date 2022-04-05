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
    std::cout << "Starting Animal Farm 2" << std::endl;

    // Test routine
#ifdef DEBUG_ENABLE
    {

        cout << "Beginning Animal Farm Test Routine..." << endl;

        //
        cout << "Test 1: \n\tConstructing a cat with default constructor and checking for\n\t"
                "proper default member variable assignment...\n";
        Cat *defaultCat = new Cat();
        assert(strcmp(defaultCat->getName(), "") == 0);
        assert(defaultCat->getName() != nullptr);
        assert(defaultCat->getGender() == UNKNOWN_GENDER);
        assert(defaultCat->getBreed() == UNKNOWN_BREED);
        assert(defaultCat->isCatFixed() == false);
        assert(defaultCat->validate() == false);

        // >>>>>>>>>>>>>>>>>>>>>>>>>  Name Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        //
        try {
            cout << "Test 2: \n\tAttempting to set _name to nullptr...";
            defaultCat->setName(nullptr);
            assert(false);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        //
        cout << "Test 3: \n\tAttempting to set _name to empty string (\"\")...";
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
        cout << "Test 5: \n\tAttempting to set name to a name with MAX_NAME_LEN...";
        char MAX_NAME1[MAX_NAME_LEN];
        memset(MAX_NAME1, 'A', MAX_NAME_LEN);
        defaultCat->setName(MAX_NAME1);
        assert(strcmp(defaultCat->getName(), MAX_NAME1) == 0);
        cout << " pass." << endl;

        //
        cout << "Test 6: \n\tTesting setName() with too long of a name...";
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
        enum Gender oldGender = defaultCat->getGender();
        enum Gender newGender = MALE;
        defaultCat->setGender(newGender);
        assert(defaultCat->getGender() != oldGender);
        assert(defaultCat->getGender() == newGender);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setBreed() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        // @todo Change test once administrative management object is implemented
        cout << "Test 8: \n\tTesting setBreed()...";
        enum Breed oldBreed = defaultCat->getBreed();
        enum Breed newBreed = MANX;
        defaultCat->setBreed(newBreed);
        assert(defaultCat->getBreed() != oldBreed);
        assert(defaultCat->getBreed() == newBreed);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  fixCat() Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        cout << "Test 9: \n\tTesting fixCat()...";
        defaultCat->fixCat();
        assert(defaultCat->isCatFixed() == true);
        cout << " pass." << endl;

        // >>>>>>>>>>>>>>>>>>>>>>>>>  setWeight Testing <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        cout << "Test 10: \n\tAttempting to set _weight to an invalid value less than 0...";
        try {
            defaultCat->setWeight(-5.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }


        cout << "Test 11: \n\tAttempting to set _weight to an invalid value of 0...";
        try {
            defaultCat->setWeight(0.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }


        cout << "Test 12: \n\tAttempting to set _weight to an invalid value greater than MAX_CAT_WEIGHT...";
        try {
            defaultCat->setWeight(MAX_CAT_WEIGHT + 1.0);
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }

        cout << "Test 13: \n\tAttempting to set _weight to a valid decimal value...";
        defaultCat->setWeight(3.14159);
        assert(defaultCat->getWeight() == (Weight) 3.14159);
        cout << " pass." << endl;

        // All member variables have been assigned valid entries
        // validate() should now yield success
        cout << "Test 14: \n\tprint()";
        assert(defaultCat->validate());
        defaultCat->print();


        cout << "\nTest 15: \n\tTesting zeroize() for destructor to see if parameter fields properly set to specified values...";
        defaultCat->zeroize();
        char zeroName[MAX_NAME_LEN];
        memset(zeroName, '0', MAX_NAME_LEN);
        assert(strcmp(defaultCat->getName(), zeroName) == 0);
        assert(defaultCat->getGender() == UNKNOWN_GENDER);
        assert(defaultCat->getBreed() == UNKNOWN_BREED);
        assert(defaultCat->isCatFixed() == false);
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
        cout << " pass." << endl;

        //
        cout << "Test 21: \n\tTesting printAllCats(), by iterating over some added cats..." << endl;
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









    }
#endif
    // End of Test routine

    /*
    printf("\nStarting Animal Farm 1\n");
    printf("....................................................................\n\n\n");

    initializeDatabase();
    addCat("Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101);
    addCat("Milo", MALE, MANX, true, 7.0, BLACK, RED, 102);
    addCat("Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103);
    addCat("Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104);
    addCat("Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105);
    addCat("Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, GREEN, RED, 106);

#ifdef DEBUG_ENABLE
    fprintf(stderr, "Beginning testing sequence\n");

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

    // colorLiteral testing
    assert(strcmp(colorLiteral(UNASSIGNED), "UNASSIGNED") == 0);
    assert(strcmp(colorLiteral(BLACK), "BLACK") == 0);
    assert(strcmp(colorLiteral(WHITE), "WHITE") == 0);
    assert(strcmp(colorLiteral(RED), "RED") == 0);
    assert(strcmp(colorLiteral(BLUE), "BLUE") == 0);
    assert(strcmp(colorLiteral(GREEN), "GREEN") == 0);
    assert(strcmp(colorLiteral(PINK), "PINK") == 0);

    // Test for empty name
    fprintf(stderr, "\nTesting for empty name\n");
    assert(addCat("", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101) == BAD_CAT);

    // Test for max name
    fprintf(stderr, "\nTesting for max name\n");
    assert(addCat(MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107) != BAD_CAT);

    // Test for name too long
    fprintf(stderr, "\nTesting addCat with a name that's too long\n");
    assert(addCat(ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108) == BAD_CAT);

    // Test for duplicate cat name
    fprintf(stderr, "\nTesting for duplicate name\n");
    assert(addCat("Chili", UNKNOWN_GENDER, SHORTHAIR, false, 10, WHITE, GREEN, 109) == BAD_CAT);

    // Test for weight zero weight
    fprintf(stderr, "\nTesting for zero weight\n");
    assert(addCat("Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110) == BAD_CAT);

    // Test for weight negative weight
    fprintf(stderr, "\nTesting for negative weight\n");
    assert(addCat("Neo", UNKNOWN_GENDER, SHORTHAIR, false, -10, WHITE, PINK, 110) == BAD_CAT);

    // Test for weight unrealistic weight
    fprintf(stderr, "\nTesting for unrealistic weight\n");
    assert(addCat("Neo", UNKNOWN_GENDER, SHORTHAIR, false, MAX_CAT_WEIGHT + 1, WHITE, PINK, 110) == BAD_CAT);

    // Test for printCat( -1 ) ;
    fprintf(stderr, "\nTesting for printCat(-1)\n");
    printCat(-1);

    // Test for out of bounds
    fprintf(stderr, "\nTesting for out-of-bounds case\n");
    printCat(MAX_CATS + 1);

    // Test finding a cat...
    fprintf(stderr, "\nTesting for finding an existing cat in the database\n");
    assert(findCat("Bella") == 2);
    fprintf(stderr, "The cat \"Bella\" has a database index of %d\n", findCat("Bella"));

    // Test deleteCat
    fprintf(stderr, "\nTesting deleteCat(\"Bella\")\n");
    deleteCat(findCat("Bella"));

    // Test not finding a cat
    fprintf(stderr, "\nTesting findCat for a cat that's not there\n");
    assert(findCat("Bella") == BAD_CAT);

    // Test addCat details
    fprintf(stderr, "\nTesting addCat index return\n");
    fprintf(stderr, "Before adding \"Oscar\" the cat; currentNumberOfCats = %lu\n", currentNumberOfCats);
    NumCats oscarIndex = addCat("Oscar", UNKNOWN_GENDER, SHORTHAIR, false, 1.1, BLUE, RED, 111);
    fprintf(stderr, "\"Oscar\" the cats database index = %lu\n", oscarIndex);
    fprintf(stderr, "After adding \"Oscar\" the cat; currentNumberOfCats = %lu\n", currentNumberOfCats);

    assert(oscarIndex != (NumCats)BAD_CAT);
    assert(oscarIndex < MAX_CATS);
    assert((int)oscarIndex == findCat("Oscar"));

    // Test updating a large name
    fprintf(stderr, "\nTesting updateCatName for a name that's exactly the maximum name length\n");
    assert(updateCatName(oscarIndex, MAX_NAME2) == true);
    printCat(oscarIndex);

    // Testing updateCatName with a name that's too long
    fprintf(stderr, "\nTesting updateCatName with a name that's too long\n");
    assert(updateCatName(0, ILLEGAL_NAME) == false);

    // Test setting an invalid cat weight
    fprintf(stderr, "\nTesting for setting an invalid cat weight\n");
    assert(updateCatWeight(oscarIndex, -1) == false);

    // Test for matching collar colors on the same cat
    fprintf(stderr, "\nTesting for matching collar colors on the same cat\n");
    assert(addCat("Luigi", MALE, MANX, true, 14.2, BLACK, BLACK, 8675309) == BAD_CAT);

    // Deleting all cats in to make testing duplicate colors and licenses easier to follow
    deleteAllCats();

    // Test for matching collar combinations against the entire database
    fprintf(stderr, "\nTesting for matching collar combinations against the entire database\n");
    addCat("Bowser", MALE, MANX, true, 14.2, BLACK, WHITE, 69);
    assert(addCat("Luigi", MALE, MANX, true, 14.2, BLACK, WHITE, 1984) == BAD_CAT);
    assert(addCat("Luigi", MALE, MANX, true, 14.2, WHITE, BLACK, 1984) == BAD_CAT);

    // Test for addCat duplicate licenses
    fprintf(stderr, "\nTesting for duplicate licenses\n");
    addCat("Luigi", MALE, MANX, true, 14.2, GREEN, WHITE, 8675309);
    assert(addCat("Mario", MALE, MANX, true, 14.2, RED, WHITE, 8675309) == BAD_CAT);

    // Resetting cats to make testing duplicate colors and licenses easier to follow
    deleteAllCats();
    // Adding new cats to play with
    addCat("Mario", MALE, MANX, false, 16.4, RED, WHITE, 1981);
    addCat("Luigi", MALE, MANX, false, 14.2, GREEN, WHITE, 1983);

    // Test for updateCat matching color combination on the same cat
    fprintf(stderr, "\nTesting for updateCat matching collar colors on the same cat\n");
    // Should be able to change Mario's collar1 color to blue
    assert(updateCatCollar1(findCat("Mario"), BLUE) == true);
    // Should not be able to change Mario's collar1 color to white; would then be white & white combo
    assert(updateCatCollar1(findCat("Mario"), WHITE) == false);
    // Should not be able to change Mario's collar2 color to blue; would then be blue & blue
    assert(updateCatCollar2(findCat("Mario"), BLUE) == false);

    // Resetting cats to make testing duplicate colors and licenses easier to follow
    deleteAllCats();
    // Adding new cats to play with
    addCat("Mario", MALE, MANX, false, 16.4, RED, WHITE, 1981);
    addCat("Luigi", MALE, MANX, false, 14.2, GREEN, WHITE, 1983);

    // Test for updateCat matching color combination against the entire database
    fprintf(stderr, "\nTesting for updateCat matching collar color combination against the entire database\n");
    assert(updateCatCollar1(findCat("Luigi"), RED) == false);

    // Test for updateCat duplicate licenses
    fprintf(stderr, "\nTesting for updateCat matching collar color combination against the entire database\n");
    assert(updateLicense(findCat("Luigi"), 1981) == false);

#endif
    printf("\n\n....................................................................\n");
    printf("Done with Animal Farm 1\n\n");

     */

    return 0;
}
