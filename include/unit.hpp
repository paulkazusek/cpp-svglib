//
//  unit.hpp

#ifndef SVGLIB_UNIT_HPP
#define SVGLIB_UNIT_HPP

namespace svglib
{
	/**
	 * \brief Defines the various types of unit an Unit can be.
	 */
	enum class UnitType : std::uint8_t
	{
		/**
		 * \brief The unit is in centimeters
		 */
		centimeter,
		/**
		 * \brief The unit is equal to the pt size of the current font
		 */
		em,
		/**
		 * \brief The unit is equal to the x-height of the current font
		 */
		ex,
		/**
		 * \brief The unit is in inches
		 */
		inch,
		/**
		 * \brief The unit is in millimeters
		 */
		millimeter,
		/**
		 * \brief The unit holds no value
		 */
		none,
		/**
		 * \brief The unit is a percentage
		 */
		percentage,
		/**
		 * \brief The unit is in picas
		 */
		pica,
		/**
		 * \brief The unit is in pixels
		 */
		pixel,
		/**
		 * \brief The unit is in points
		 */
		point,
		/**
		 * \brief The unit has no unit identifier
		 */
		user
	};

	/**
	 * \brief Represent a unit in a Scalable Vector Graphics
	 */
	class Unit final
	{
	public:
		constexpr Unit() = delete;

		/**
		 * \brief Initializes a new instance of the Unit
		 * \param value - The value
		 * \param unit - The unit
		 */
		constexpr Unit( const long double value, UnitType unit ) noexcept
			: value_ { value }
			, type_ { unit }
		{}

		/**
		 * \brief Initializes a new instance of the Unit. Converting Constructor
		 * \param value - The value
		 */
		constexpr Unit( const long double value ) noexcept
			: value_ { value }
			, type_ { UnitType::user }
		{}

		/**
		 * \brief Gets the value of the unit
		 * \return A long double
		 */
		[[nodiscard]]
		constexpr long double value() const noexcept
		{
			return value_;
		}

		/**
		 * \brief Gets the UnitType of unit
		 * \return An UnitType
		 */
		[[nodiscard]]
		constexpr UnitType type() const noexcept
		{
			return type_;
		}

	private:
		long double value_;
		UnitType type_;
	};

	constexpr Unit operator"" _cm( const long double value )
	{
		return Unit { value, UnitType::centimeter };
	}

	constexpr Unit operator"" _em( const long double value )
	{
		return Unit { value, UnitType::em };
	}

	constexpr Unit operator"" _ex( const long double value )
	{
		return Unit { value, UnitType::ex };
	}

	constexpr Unit operator"" _in( const long double value )
	{
		return Unit { value, UnitType::inch };
	}

	constexpr Unit operator"" _mm( const long double value )
	{
		return Unit { value, UnitType::millimeter };
	}

	constexpr Unit operator"" _none( const long double value )
	{
		return Unit { value, UnitType::none };
	}

	constexpr Unit operator"" _percentage( const long double value )
	{
		return Unit { value, UnitType::percentage };
	}

	constexpr Unit operator"" _pica( const long double value )
	{
		return Unit { value, UnitType::pica };
	}

	constexpr Unit operator"" _px( const long double value )
	{
		return Unit { value, UnitType::pixel };
	}

	constexpr Unit operator"" _pt( const long double value )
	{
		return Unit { value, UnitType::point };
	}
}

template <>
struct std::formatter<svglib::UnitType> : std::formatter<std::string_view>
{
	auto format( const svglib::UnitType& type, std::format_context& context ) const
	{
		string_view out;
		switch (type)
		{
			case svglib::UnitType::centimeter:	out = "cm";		break;
			case svglib::UnitType::em:			out = "em";		break;
			case svglib::UnitType::ex:			out = "ex";		break;
			case svglib::UnitType::inch:		out = "in";		break;
			case svglib::UnitType::millimeter:	out = "mm";		break;
			case svglib::UnitType::none:		out = "none";	break;
			case svglib::UnitType::percentage:	out = "%";		break;
			case svglib::UnitType::pica:		out = "pc";		break;
			case svglib::UnitType::pixel:		out = "px";		break;
			case svglib::UnitType::point:		out = "pt";		break;
			case svglib::UnitType::user:		out = "";		break;
		}
		return formatter<string_view>::format( out, context );
	}
};

template <>
struct std::formatter<svglib::Unit> : std::formatter<std::string>
{
	auto format( const svglib::Unit& unit, std::format_context& context ) const
	{
		const auto out = std::format( "{:.2f}{}", unit.value(), unit.type() );

		return formatter<string>::format( out, context );
	}
};

#endif