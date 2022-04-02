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

#include <assert.h> // For assert()
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS and EXIT_FAILURE
#include <string.h>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

int main(void)
{
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

    return 0;
}
