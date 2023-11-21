//
//  serializeable.hpp

#ifndef SVGLIB_SERIALIZEABLE_HPP
#define SVGLIB_SERIALIZEABLE_HPP

namespace svglib
{
	/**
	 * \brief
	 */
	class Serializeable
	{
	public:
		explicit constexpr Serializeable() = default;
		virtual constexpr ~Serializeable() = default;

		virtual std::string serialize() const = 0;
	};
}

#endif