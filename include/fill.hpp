//
//  fill.hpp

#ifndef FILL_HPP
#define FILL_HPP

#include <optional>

namespace svglib
{
	class Color;

	class Fill
	{
	public:
		constexpr Fill() = delete;

		constexpr Fill( Color color, const std::optional<double>& opacity = std::nullopt )
		//: color_ { std::move( color ) }
		: color_ { color }
		, opacity_ { opacity }
		{}

	private:
		Color color_;
		std::optional<double> opacity_;
	};
};

#endif