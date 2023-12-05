//
//  serializeable.hpp

#ifndef SVGLIB_SERIALIZEABLE_HPP
#define SVGLIB_SERIALIZEABLE_HPP

namespace svglib
{
	/**
	 * \brief
	 */
	struct Serializeable
	{
		explicit constexpr Serializeable() = default;
		virtual constexpr ~Serializeable() = default;
		constexpr Serializeable& operator=( const Serializeable& other ) = default;

		[[nodiscard]] virtual std::string serialize() const = 0;
	};
}

#endif