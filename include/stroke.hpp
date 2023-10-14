//
//  fill.hpp

#ifndef STROKE_HPP
#define STROKE_HPP

#include "opacity.hpp"
#include "width.hpp"

#include <optional>

namespace svglib
{
	class Color;

	class Stroke final : public Serializeable
	{
	public:
		constexpr Stroke() = delete;

		constexpr Stroke( const Color& color, const Width& width, std::optional<Opacity> opacity = std::nullopt )
		: color_ { color }
		, width_ { width }
		, opacity_ { std::move( opacity ) }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			std::string opacity;
			if ( opacity_ )
				opacity = " stroke-" + opacity_.value().serialize();

			return std::format( R"(stroke="{}" stroke-{}")", color_.serialize(), width_.serialize() ) + opacity;
		}

	private:
		Color color_;
		Width width_;
		std::optional<Opacity> opacity_;
	};
};

#endif