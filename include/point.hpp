//
//  point.hpp

#ifndef POINT_HPP
#define POINT_HPP

#include "serializeable.hpp"

#include <string>

namespace svglib
{
	/**
	 * \brief
	 */
	class Point : public Serializeable
	{
	public:
		constexpr Point() = delete;

		constexpr Point( const double& x, const double& y );

		constexpr ~Point() = default;

		[[nodiscard]] constexpr auto x() const -> double;

		[[nodiscard]] constexpr auto y() const -> double;

		constexpr auto operator==( const Point& other ) const -> bool;

		//[[nodiscard]] /*constexpr*/ std::string serialize() const override;
		[[nodiscard]] constexpr const char* serialize() const override;

	private:
		double x_;
		double y_;
	};

	constexpr Point::Point( const double& x, const double& y )
	: x_ { x }
	, y_ { y }
	{}

	constexpr auto Point::x() const -> double
	{
		return x_;
	}

	constexpr auto Point::y() const -> double
	{
		return y_;
	}

	constexpr auto Point::operator==(const Point& other) const -> bool
	{
		return x() == other.x() and y() == other.y();
		//return std::fabs( x() - other.x() ) <= std::numeric_limits<double>::epsilon()
		//			* std::fmax( std::fabs( x() ), std::fabs( other.x() ) )
		//	and std::fabs( y() - other.y() ) <= std::numeric_limits<double>::epsilon()
		//			* std::fmax( std::fabs( y() ), std::fabs( other.y() ) );
	}

	/*constexpr*/
	//inline std::string Point::serialize() const
	constexpr const char* Point::serialize() const
	{
		const auto x_start = "x=\"";
		const auto y_start = "\" y=\"";
		const auto end = "\"";

		const auto x_value = "10.0";
		const auto y_value = "10.5";

		//auto result = static_cast<char*>( malloc( ( strlen( x_start ) + strlen( x_value ) + strlen( y_start ) + strlen( y_value ) + strlen( x_value ) ) * sizeof( char ) ) );

		return "";
		//return R"(x="" y="")";
	}
}

#endif