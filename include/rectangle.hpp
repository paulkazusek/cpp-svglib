//
//  line.hpp

#ifndef SVGLIB_RECTANGLE_HPP
#define SVGLIB_RECTANGLE_HPP

#include "unit.hpp"
#include "serializeable.hpp"

namespace svglib
{
	/**
	 * \brief
	 */
	class Rectangle : public Serializeable
	{
	public:
		constexpr Rectangle() = delete;

		constexpr Rectangle( const Point& start, const Point& end )
			: start_ { start }
			, end_ { end }
		{}

		constexpr ~Rectangle() override = default;

		[[nodiscard]] constexpr auto x() const -> Unit
		{
			return x_;
		}

		[[nodiscard]] constexpr auto y() const -> Unit
		{
			return y_;
		}

		[[nodiscard]] constexpr auto width() const -> Unit
		{
			return width_;
		}

		[[nodiscard]] constexpr auto height() const -> Unit
		{
			return height_;
		}

		[[nodiscard]]
		auto serialize() const -> std::string override
		{
			return std::format( R"(x="{}" y="{}" width="{}" height="{}")"
								, x_
								, y_
								, width_
								, height_
			);
		}

	private:
		Unit x_;
		Unit y_;
		Unit width_;
		Unit height_;
	};	
}

#endif