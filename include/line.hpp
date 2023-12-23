//
//  line.hpp

#ifndef SVGLIB_LINE_HPP
#define SVGLIB_LINE_HPP

#include "shape.hpp"

namespace svglib
{
	class Point;

	/**
	 * \brief
	 */
	class Line final : public Shape
	{
	public:
		constexpr Line() = delete;

		constexpr Line( const Point& start, const Point& end, const Stroke& stroke )
			: Shape( stroke )
			, start_ { start }
			, end_ { end }
		{}

		constexpr ~Line() override = default;

		[[nodiscard]] constexpr auto start() const -> Point
		{
			return start_;
		}

		[[nodiscard]] constexpr auto end() const -> Point
		{
			return end_;
		}

		[[nodiscard]]
		auto serialize() const -> std::string override
		{
			return std::format( R"(<line x1="{}" y1="{}" x2="{}" y2="{} {} />")"
								, start_.x()
								, start_.y()
								, end_.x()
								, end_.y()
								, stroke_.serialize()
			);
		}

	private:
		Point start_;
		Point end_;
	};	
}

#endif