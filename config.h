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

#include <iostream>
#include <iomanip>
#include <string>

#define PROGRAM_NAME "Animal Farm 3"

/////////////////////////////////// Formatting Macros ///////////////////////////////////
/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP \
 /* Print =========================================================== */ \
 std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl

/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
 std::cout << std::setfill( ' ' ) /* Space pad */ \
 << std::left /* Left justify */ \
 << std::boolalpha /* Print `true` or `false` for `bool`s */ \
 << std::setw(8) << (className) \
 << std::setw(20) << (member) \
 << std::setw(52) /* (data) */

/// Maximum Name Length that a cat is allowed to have
#define MAX_NAME_LEN 30

#endif //EE205_ANIMAL_FARM_CONFIG_H
