//
//  line.hpp

#ifndef LINE_HPP
#define LINE_HPP

namespace svglib
{
	class Point;

	/**
	 * \brief
	 */
	class Line
	{
	public:
		constexpr Line() = delete;

		constexpr Line( const Point& start, const Point& end );

		constexpr ~Line() = default;

		[[nodiscard]] constexpr auto start() const -> Point;

		[[nodiscard]] constexpr auto end() const -> Point;

	private:
		Point start_;
		Point end_;
	};

	constexpr Line::Line( const Point& start, const Point& end )
	: start_ { start }
	, end_ { end }
	{}

	[[nodiscard]] constexpr auto Line::start() const -> Point
	{
		return start_;
	}

	[[nodiscard]] constexpr auto Line::end() const -> Point
	{
		return end_;
	}
}

#endif