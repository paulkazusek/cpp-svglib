//
//  fill.hpp

#ifndef SVGLIB_STROKE_HPP
#define SVGLIB_STROKE_HPP

#include <optional>

namespace svglib
{
	class Color;

	class Stroke final : public Serializeable
	{
	public:
		constexpr Stroke() = delete;

		constexpr Stroke( const Unit& width, const Color& color, const std::optional<Unit>& opacity = std::nullopt )
			: width_ { width }
			, color_ { color }
			, opacity_ { opacity }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			std::string opacity;
			if ( opacity_ )
				opacity = std::format( R"( stroke-opacity="{}")", opacity_.value() );

			return std::format( R"(stroke="{}" stroke-width="{}")", color_.serialize(), width_ ) + opacity;
		}

	private:
		Unit width_;
		Color color_;
		std::optional<Unit> opacity_{};
	};
}

#endif