///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H

#include <ostream>
#include <iostream>
#include <string>
#include <exception>

#include <assert.h>
#include <string.h> // For handling of c style strings

#include "config.h"

// Option for default max weight to count as a set weight
// (useful for specified required behavior in Animal Farm 3)
#define AUTO_DEFAULT_MAX_WEIGHT

using namespace std;

typedef float t_weight;

class Weight
{
public:  /////////////////////////////////// Enumerations ///////////////////////////////////
	enum UnitOfWeight
	{
		POUNDS,
		KILOS,
		SLUGS
	};

protected:  /////////////////////////////////// Member Variables ///////////////////////////////////
	UnitOfWeight _unitOfWeight{ DEFAULT_UNIT_OF_WEIGHT };
	t_weight _weight{ UNKNOWN_WEIGHT };
	t_weight _maxWeight{ DEFAULT_MAX_WEIGHT };
	bool _bIsKnown{ false }; ///< bool flag for if _weight has been set to a valid value
	bool _bHasMax{ false }; ///< bool flag for if _maxWeight has been set to a valid value

public:  /////////////////////////////////// Constants ///////////////////////////////////
	static const t_weight UNKNOWN_WEIGHT;
	static const t_weight KILOS_IN_A_POUND;
	static const t_weight SLUGS_IN_A_POUND;
	static const UnitOfWeight DEFAULT_UNIT_OF_WEIGHT;
	static const t_weight DEFAULT_MAX_WEIGHT;
	static const string POUND_LITERAL;
	static const string SLUG_LITERAL;
	static const string KILO_LITERAL;

public:  /////////////////////////////////// Class Constructors ///////////////////////////////////
	// ↓ #1 Default Constructor: delegates to #7 with all default values
	Weight() noexcept;

	// ↓ #2 only newWeight parameter provided: delegates to #7 with default values for _unitOfWeight and _maxWeight
	explicit Weight( t_weight newWeight );

	// ↓ #3 Only newUnitOfWeight parameter provided: delegates to #7 with default values for _weight and _unitOfWeight
	explicit Weight( UnitOfWeight newUnitOfWeight ) noexcept;

	// ↓ #4 newWeight and newUnitOfWeight parameters provided: delegates to #7 with default value for _maxWeight
	Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight ) noexcept;

	// ↓ #5  newWeight and newMaxWeight provided: delegates to #7 with default value for _unitOfWeight
	Weight( t_weight newWeight, t_weight newMaxWeight ) noexcept;

	// ↓ #6  newUnitOfWeight and newMaxWeight provided: delegates to #7 with default value for _weight
	Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) noexcept;

	// ↓ #7  all member variables provided as parameters
	Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) noexcept;

public:  /////////////////////////////////// Static Methods ///////////////////////////////////
	static t_weight fromKilogramsToPounds( const t_weight weightInKilos ) noexcept;

	static t_weight fromPoundsToKilograms( const t_weight weightInPounds ) noexcept;

	static t_weight fromSlugsToPounds( const t_weight weightInSlugs ) noexcept;

	static t_weight fromPoundsToSlugs( const t_weight weightInPounds ) noexcept;

	static t_weight convertWeight( const t_weight fromWeight, const UnitOfWeight fromUnit, const UnitOfWeight toUnit ) noexcept;

public:    /////////////////////////////////// Getters ///////////////////////////////////
	t_weight getWeight() const noexcept;

	t_weight getWeight( const UnitOfWeight weightUnits ) const noexcept;

	t_weight getMaxWeight() const noexcept;

	UnitOfWeight getUnitOfWeight() const noexcept;

public: /////////////////////////////////// Setters ///////////////////////////////////
	void setWeight( const t_weight newWeight );

	void setWeight( const t_weight newWeight, UnitOfWeight weightUnits );


public:    /////////////////////////////////// Public Methods ///////////////////////////////////
	bool weightIsKnown() const noexcept;

	bool hasMaxWeight() const noexcept;

	void dump() const noexcept;

	void setMaxWeight( const t_weight newMaxWeight );

public:    /////////////////////////////////// Validation Methods ///////////////////////////////////
	static bool weightIsValid( const t_weight checkWeight, const t_weight checkMaxWeight ) noexcept;

	static bool maxWeightIsValid( const t_weight checkMaxWeight ) noexcept;

	bool validate() const noexcept;

public:  /////////////////////////////////// Overloaded Operators ///////////////////////////////////
	bool operator==( const Weight &rhs ) const;

	bool operator<( const Weight &rhs ) const;

	Weight &operator+=( const t_weight &rhs_weight );

};

/////////////////////////////////// Externally Scoped Overloaded Operators ///////////////////////////////////
std::ostream &operator<<( std::ostream &lhs_stream, const Weight::UnitOfWeight rhsUnit );

std::ostream &operator<<( std::ostream &lhs_stream, const Weight rhsWeight );

#endif //EE205_LAB12A_FATCAT_WEIGHT_H
