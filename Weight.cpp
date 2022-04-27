///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 3.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"

/////////////////////////////////// Constants //////////////////////////////////////
const t_weight Weight::UNKNOWN_WEIGHT = 0;
const t_weight Weight::KILOS_IN_A_POUND = 0.453592;
const t_weight Weight::SLUGS_IN_A_POUND = 0.031081;
const Weight::UnitOfWeight Weight::DEFAULT_UNIT_OF_WEIGHT = POUNDS;
const t_weight Weight::DEFAULT_MAX_WEIGHT = 40;
const string Weight::POUND_LITERAL = "lbs";
const string Weight::SLUG_LITERAL = "slugs";
const string Weight::KILO_LITERAL = "kgs";

/////////////////////////////////// Class Constructors //////////////////////////////////////
// ↓ #1 Default Constructor: delegates to #7 with all default values
Weight::Weight() noexcept : Weight( UNKNOWN_WEIGHT, DEFAULT_UNIT_OF_WEIGHT, UNKNOWN_WEIGHT ) {}

// ↓ #2 only newWeight parameter provided: delegates to #7 with default values for _unitOfWeight and _maxWeight
Weight::Weight( t_weight newWeight ) : Weight( newWeight, DEFAULT_UNIT_OF_WEIGHT, UNKNOWN_WEIGHT ) {}

// ↓ #3 Only newUnitOfWeight parameter provided: delegates to #7 with default values for _weight and _unitOfWeight
Weight::Weight( Weight::UnitOfWeight newUnitOfWeight ) noexcept : Weight( UNKNOWN_WEIGHT, newUnitOfWeight, UNKNOWN_WEIGHT ) {}

// ↓ #4 newWeight and newUnitOfWeight parameters provided: delegates to #7 with default value for _maxWeight
Weight::Weight( t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight ) noexcept : Weight( newWeight, newUnitOfWeight, UNKNOWN_WEIGHT ) {}

// ↓ #5  newWeight and newMaxWeight provided: delegates to #7 with default value for _unitOfWeight
Weight::Weight( t_weight newWeight, t_weight newMaxWeight ) noexcept : Weight( newWeight, DEFAULT_UNIT_OF_WEIGHT, newMaxWeight ) {}

// ↓ #6  newUnitOfWeight and newMaxWeight provided: delegates to #7 with default value for _weight
Weight::Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) noexcept : Weight( UNKNOWN_WEIGHT, newUnitOfWeight, newMaxWeight ) {}

// ↓ #7  all member variables provided as parameters
Weight::Weight( t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight ) noexcept : _unitOfWeight{ newUnitOfWeight }
{
	if( maxWeightIsValid( newMaxWeight ))
	{
		_maxWeight = newMaxWeight;
		_bHasMax = true;
	}
	else
	{
		_maxWeight = DEFAULT_MAX_WEIGHT;

		// Option, set at top of Weight.h, for default max weight to count as a validly set weight
		// (useful for specified required behavior in Animal Farm 3)
		if( AUTO_DEFAULT_MAX_WEIGHT )
		{
			_bHasMax = true;
		}
	}

	if( weightIsValid( newWeight, _maxWeight ))
	{
		_weight = newWeight;
		_bIsKnown = true;
	}
	else
	{
		_weight = UNKNOWN_WEIGHT;
	}
}

/////////////////////////////////// Static Methods //////////////////////////////////////
t_weight Weight::fromKilogramsToPounds( const t_weight weightInKilos ) noexcept
{
	return weightInKilos / KILOS_IN_A_POUND;
}

t_weight Weight::fromPoundsToKilograms( const t_weight weightInPounds ) noexcept
{
	return weightInPounds * KILOS_IN_A_POUND;
}

t_weight Weight::fromSlugsToPounds( const t_weight weightInSlugs ) noexcept
{
	return weightInSlugs / SLUGS_IN_A_POUND;
}

t_weight Weight::fromPoundsToSlugs( const t_weight weightInPounds ) noexcept
{
	return weightInPounds * SLUGS_IN_A_POUND;
}

t_weight Weight::convertWeight( const t_weight fromWeight, const Weight::UnitOfWeight fromUnit, const Weight::UnitOfWeight toUnit ) noexcept
{
	switch( fromUnit )
	{
		case POUNDS:
			switch( toUnit )
			{
				case POUNDS:
					return fromWeight;
				case SLUGS:
					return fromPoundsToSlugs( fromWeight );
				case KILOS:
					return fromPoundsToKilograms( fromWeight );
				default:
					assert( 0 );
			}

		case SLUGS:
			switch( toUnit )
			{
				case POUNDS:
					return fromSlugsToPounds( fromWeight );
				case SLUGS:
					return fromWeight;
				case KILOS:
					return fromPoundsToKilograms( fromSlugsToPounds( fromWeight ));
				default:
					assert( 0 );
			}

		case KILOS:
			switch( toUnit )
			{
				case POUNDS:
					return fromKilogramsToPounds( fromWeight );
				case SLUGS:
					return fromPoundsToSlugs( fromKilogramsToPounds( fromWeight ));
				case KILOS:
					return fromWeight;
				default:
					assert( 0 );
			}
		default:
			assert( 0 );
	}
}

/////////////////////////////////// Getters ///////////////////////////////////
t_weight Weight::getWeight() const noexcept
{
	return _bIsKnown ? _weight : 0;
}

t_weight Weight::getWeight( const Weight::UnitOfWeight weightUnits ) const noexcept
{
	if( _bIsKnown )
	{
		return convertWeight( _weight, _unitOfWeight, weightUnits );
	}
	return 0; // (!_bisKnown)
}

t_weight Weight::getMaxWeight() const noexcept
{
	return _maxWeight;
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept
{
	return _unitOfWeight;
}

/////////////////////////////////// Setters ///////////////////////////////////
void Weight::setWeight( const t_weight newWeight )
{
	if( weightIsValid( newWeight, _maxWeight ))
	{
		_bIsKnown = true;
		_weight = newWeight;
	}
}

void Weight::setWeight( const t_weight newWeight, Weight::UnitOfWeight weightUnits )
{
	if( weightIsValid( newWeight, _maxWeight ))
	{
		_weight = convertWeight( newWeight, _unitOfWeight, weightUnits );
	}
}

void Weight::setMaxWeight( const t_weight newMaxWeight )
{
	// Can only set _maxWeight if it isn't already set    ↓
	if( maxWeightIsValid( newMaxWeight ) && !_bHasMax )
	{
		_maxWeight = newMaxWeight;
		_bHasMax = true;
	}
}

/////////////////////////////////// Public Methods ///////////////////////////////////
bool Weight::weightIsKnown() const noexcept
{
	return _bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept
{
	return _bHasMax;
}

void Weight::dump() const noexcept
{
	FORMAT_LINE_FOR_DUMP( "Weight", "this" ) << this << std::endl;
	FORMAT_LINE_FOR_DUMP( "Weight", "isKnown" ) << _bIsKnown << std::endl;
	FORMAT_LINE_FOR_DUMP( "Weight", "weight" ) << _weight << std::endl;
	FORMAT_LINE_FOR_DUMP( "Weight", "unitOfWeight" ) << _unitOfWeight << std::endl;
	FORMAT_LINE_FOR_DUMP( "Weight", "hasMax" ) << _bHasMax << std::endl;
	FORMAT_LINE_FOR_DUMP( "Weight", "maxWeight" ) << _maxWeight << std::endl;
}

/////////////////////////////////// Validation Methods ///////////////////////////////////
bool Weight::weightIsValid( const t_weight checkWeight, const t_weight checkMaxWeight ) noexcept
{
	return ( checkWeight > 0 && checkWeight != UNKNOWN_WEIGHT && checkWeight <= checkMaxWeight );
}

bool Weight::maxWeightIsValid( const t_weight checkMaxWeight ) noexcept
{
	return ( checkMaxWeight > 0 && checkMaxWeight < DEFAULT_MAX_WEIGHT );
}

bool Weight::validate() const noexcept
{
	return ( _bIsKnown && ( _weight <= _maxWeight ));
}

/////////////////////////////////// Overloaded Operators ///////////////////////////////////
bool Weight::operator==( const Weight &rhs ) const
{
	t_weight lhs_weight = ( _bIsKnown ) ? getWeight( Weight::POUNDS ) : 0;
	t_weight rhs_weight = ( rhs._bIsKnown ) ? rhs.getWeight( Weight::POUNDS ) : 0;
	return lhs_weight == rhs_weight;
}

bool Weight::operator<( const Weight &rhs ) const
{
	t_weight lhs_weight = ( _bIsKnown ) ? getWeight( Weight::POUNDS ) : 0;
	t_weight rhs_weight = ( rhs._bIsKnown ) ? rhs.getWeight( Weight::POUNDS ) : 0;
	return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=( const t_weight &rhs_weight )
{
	t_weight lhs_weight = ( _bIsKnown ) ? getWeight( Weight::POUNDS ) : 0;
	t_weight sum = lhs_weight + rhs_weight;
	if( !weightIsValid( sum, _maxWeight ))
	{
		throw invalid_argument( PROGRAM_NAME
		                        " += operation results is an invalid weight!" );
	}
	setWeight( sum );
	return *this;
}

/////////////////////////////////// Externally Scoped Overloaded Operators ///////////////////////////////////
std::ostream &operator<<( ostream &lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight )
{
	switch( rhs_UnitOfWeight )
	{
		case Weight::POUNDS:
			return lhs_stream << Weight::POUND_LITERAL;
		case Weight::KILOS:
			return lhs_stream << Weight::KILO_LITERAL;
		case Weight::SLUGS:
			return lhs_stream << Weight::SLUG_LITERAL;
		default:
			throw out_of_range( PROGRAM_NAME " Weight Error: The unit can not be converted to a string!" );
	}
}

std::ostream &operator<<( std::ostream &lhs_stream, const Weight rhs_Weight )
{
	stringstream stringBuffer;

	if( !rhs_Weight.weightIsKnown() && !rhs_Weight.hasMaxWeight())
	{
		lhs_stream << "Unknown";
		return lhs_stream;
	}
	else if( rhs_Weight.weightIsKnown())
	{
		stringBuffer << rhs_Weight.getWeight();
	}
	else
	{
		stringBuffer << "Unknown";
	}

	if( rhs_Weight.hasMaxWeight())
	{
		stringBuffer << " out of " << rhs_Weight.getMaxWeight();
	}

	stringBuffer << " " << rhs_Weight.getUnitOfWeight();

	return lhs_stream << stringBuffer.str();
}














