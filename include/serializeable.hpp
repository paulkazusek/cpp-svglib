//
//  serializeable.hpp

#ifndef SERIALIZEABLE_HPP
#define SERIALIZEABLE_HPP

namespace svglib
{
	/**
	 * \brief
	 */
	class Serializeable
	{
	public:
		constexpr Serializeable() = default;

		virtual constexpr ~Serializeable() = default;

		//[[nodiscard]] virtual constexpr std::string serialize() const = 0;
		[[nodiscard]] virtual constexpr const char* serialize() const = 0;
	};
}

#endif