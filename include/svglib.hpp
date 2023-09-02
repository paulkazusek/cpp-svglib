//
//  svglib.hpp

#ifndef SVGLIB_HPP
#define SVGLIB_HPP

#include "color.hpp"
#include "size.hpp"


namespace svglib
{
	class Point
	{
	public:
		constexpr Point() = delete;

		constexpr Point( const double& x, const double& y )
			: x_ { x }, y_ { y }
		{}

		constexpr ~Point() = default;

		[[nodiscard]] constexpr auto x() const
		{
			return x_;
		}

		[[nodiscard]] constexpr auto y() const
		{
			return y_;
		}

		constexpr auto operator==( const Point& other ) const -> bool
		{
			return x() == other.x() and y() == other.y();
		}

	private:
		double x_;
		double y_;
	};
}

#endif