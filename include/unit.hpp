//
//  unit.hpp

#ifndef UNIT_HPP
#define UNIT_HPP

namespace svglib
{
	enum class Unit : std::uint8_t
	{
		/**
		 * \brief decimal number
		 */
		number,
		/**
		 * \brief percentage 
		 */
		percentage
	};
};

#endif