//
//  fill.hpp

#ifndef FILL_HPP
#define FILL_HPP

#include <optional>

class Color;

namespace svglib
{
	class Fill
	{
	public:
		constexpr Fill() = delete;

		constexpr Fill( Color color, const std::optional<double>& opacity = std::nullopt )
		: color_ { std::move( color ) }
		, opacity_ { opacity }
		{}

	private:
		Color color_;
		std::optional<double> opacity_;
	};
};

#endif