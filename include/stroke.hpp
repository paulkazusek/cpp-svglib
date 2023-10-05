//
//  fill.hpp

#ifndef STROKE_HPP
#define STROKE_HPP

#include <optional>

namespace svglib
{
	class Color;

	class Stroke final : public Serializeable
	{
	public:
		constexpr Stroke() = delete;

		constexpr Stroke( const Color& color, const double& width = 1.0, const std::optional<double>& opacity = std::nullopt )
		: color_ { color }
		, width_ { width }
		, opacity_ { opacity }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			if /*constexpr*/ ( width_ < 0 )
				return std::string{};

			std::string opacity;
			if /*constexpr*/ ( opacity_ and isOpacityValid() )
				opacity = std::format( " stroke-opacity=\"{:.2f}\"", opacity_.value() );

			return std::format( R"(stroke="{}" stroke-width="{:.2f}")", color_.serialize(), width_ ) + opacity;
		}

	private:
		[[nodiscard]] constexpr bool isOpacityValid() const
		{
			return opacity_.value() >= 0.0 and opacity_.value() <= 1.0 ? true : false;
		}

		Color color_;
		double width_;
		std::optional<double> opacity_;
	};
};

#endif