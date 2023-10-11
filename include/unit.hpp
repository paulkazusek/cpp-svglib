//
//  unit.hpp

#ifndef UNIT_HPP
#define UNIT_HPP

namespace svglib
{
	enum class Unit : std::uint8_t
	{
		/**
		 * \brief decimal value ranging from 0-1
		 */
		number,
		/**
		 * \brief percentage at which we want to set the opacity of the element
		 */
		percentage
	};
};

#endif