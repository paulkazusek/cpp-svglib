//
//  fill.hpp

#ifndef SVGLIB_FILL_HPP
#define SVGLIB_FILL_HPP

#include "opacity.hpp"

#include <optional>

namespace svglib
{
	class Color;

	class Fill final : public Serializeable
	{
	public:
		constexpr Fill() = delete;

		constexpr Fill( const Color& color, const std::optional<Unit>& opacity = std::nullopt )
			: color_ { color }
			, opacity_ { opacity }
		{}

		[[nodiscard]] std::string serialize() const override
		{
			std::string opacity;
			if( opacity_ )
				opacity = std::format( R"( fill-opacity="{}")", opacity_.value());

			return std::format( R"(fill="{}")", color_.serialize() ) + opacity;
		}

	private:
		Color color_;
		std::optional<Unit> opacity_{};
	};
}

#endif