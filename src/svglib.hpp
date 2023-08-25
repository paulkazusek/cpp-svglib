//
//  svglib.hpp

#ifndef SVGLIB_HPP
#define SVGLIB_HPP

#include "color.hpp"

#include <array>
//#include <string>
#include <format>
#include <string_view>
#include <stdexcept>
#include <algorithm>

namespace svglib
{
	

	

	/**
	 * \brief
	 */
	class Size final
	{
	public:
		constexpr Size() = delete;

		constexpr Size( const double& width, const double& height )
			: width_ { width }, height_ { height }
		{}

		constexpr ~Size() = default;

		[[nodiscard]] constexpr auto width() const
		{
			return width_;
		}

		[[nodiscard]] constexpr auto height() const
		{
			return height_;
		}

	private:
		double width_;
		double height_;
	};

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