///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file config.h
/// @version 2.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_ANIMAL_FARM_CONFIG_H
#define EE205_ANIMAL_FARM_CONFIG_H

#define PROGRAM_NAME "Animal Farm 2"

/// Default name given to a cat upon instantiation if not specified
#define DEFAULT_NAME ""

/// Maximum Name Length that a cat is allowed to have
#define MAX_NAME_LEN 30

/// Maximum Weight that a cat is allowed to have
#define MAX_CAT_WEIGHT 100.0

/// Default weight of a cat before being assigned
#define UNKNOWN_WEIGHT -1

/// Format a line for printing the members of a class
#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(10) << (member) << setw(52)

#endif //EE205_ANIMAL_FARM_CONFIG_H
