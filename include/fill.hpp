//
//  fill.hpp

#ifndef FILL_HPP
#define FILL_HPP

#include "opacity.hpp"

#include <optional>

namespace svglib
{
	class Color;

	class Fill final : public Serializeable
	{
	public:
		constexpr Fill() = delete;

		constexpr Fill( Color color, std::optional<Opacity> opacity = std::nullopt )
		//: color_ { std::move( color ) }
		: color_ { color }
		, opacity_ { std::move( opacity ) }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			std::string opacity;
			if( opacity_ )
				opacity = " fill-" + opacity_.value().serialize();

			return std::format( R"(fill="{}")", color_.serialize() ) + opacity;
		}

	private:
		Color color_;
		std::optional<Opacity> opacity_;
	};
};

#endif