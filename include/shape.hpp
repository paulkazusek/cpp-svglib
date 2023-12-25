//
//  shape.hpp

#ifndef SVGLIB_SHAPE_HPP
#define SVGLIB_SHAPE_HPP

#include "serializeable.hpp"
#include "stroke.hpp"
#include "fill.hpp"

#include <optional>

namespace svglib
{
	/**
	 * \brief
	 */
	class Shape : public Serializeable
	{
	public:
		explicit constexpr Shape() = delete;
		constexpr Shape( Stroke stroke, std::optional<Fill> fill = std::nullopt )
			: stroke_{ std::move( stroke ) }
			, fill_{ std::move( fill ) }
		{}

		constexpr ~Shape() override = default;
		constexpr Shape& operator=( const Shape& other ) = default;

		[[nodiscard]] std::string serialize() const override = 0;

	protected:
		Stroke stroke_;
		std::optional<Fill> fill_;
	};
}
#endif