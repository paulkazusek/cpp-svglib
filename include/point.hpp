//
//  point.hpp

#ifndef SVGLIB_POINT_HPP
#define SVGLIB_POINT_HPP

#include "unit.hpp"
#include "serializeable.hpp"

#include <format>
#include <string>

namespace svglib
{
	/**
	 * \brief
	 */
	class Point : public Serializeable
	{
	public:
		explicit constexpr Point() = delete;

		constexpr Point( const Unit& x, const Unit& y ) noexcept
			: x_ { x }
			, y_ { y }
		{}

		//constexpr Point( const Point& ) = default;
		Point& operator=( const Point& other ) = default;
		constexpr ~Point() override = default;

		[[nodiscard]]
		constexpr auto x() const -> Unit
		{
			return x_;
		}

		[[nodiscard]]
		constexpr auto y() const -> Unit
		{
			return y_;
		}

		[[nodiscard]]
		auto serialize() const -> std::string override
		{
			return std::format( R"("{}")", *this );
		}
		//constexpr auto operator==( const Point& other ) const -> bool;

	private:
		Unit x_;
		Unit y_;
	};

	//constexpr auto Point::operator==(const Point& other) const -> bool
	//{
	//	return x() == other.x() and y() == other.y();
	//	//return std::fabs( x() - other.x() ) <= std::numeric_limits<double>::epsilon()
	//	//			* std::fmax( std::fabs( x() ), std::fabs( other.x() ) )
	//	//	and std::fabs( y() - other.y() ) <= std::numeric_limits<double>::epsilon()
	//	//			* std::fmax( std::fabs( y() ), std::fabs( other.y() ) );
	//}
	
	constexpr Point make_point( const Unit& x, const Unit& y ) noexcept
	{
		return Point { x, y };
	}

	std::shared_ptr<Point> make_shared_point( const Unit x, const Unit y ) noexcept
	{
		return std::make_shared<Point>( x, y );
	}
}

template <>
struct std::formatter<svglib::Point> : std::formatter<std::string>
{
	auto format( const svglib::Point& point, std::format_context& context ) const
	{
		const auto out = std::format( R"(x="{}" y="{}")", point.x(), point.x() );

		return formatter<string>::format( out, context );
	}
};

#endif