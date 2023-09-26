//
//  fill.hpp

#ifndef STROKE_HPP
#define STROKE_HPP

#include <optional>

namespace svglib
{
	class Color;

	class Stroke
	{
	public:
		constexpr Stroke() = delete;

		constexpr Stroke( Color color, const double& width, const std::optional<double>& opacity = std::nullopt )
		: color_ { color }
		, width_ { width }
		, opacity_ { opacity }
		{}

	private:
		Color color_;
		double width_;
		std::optional<double> opacity_;
	};
};

#endif