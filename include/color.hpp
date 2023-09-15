//
//  color.hpp

#ifndef COLOR_HPP
#define COLOR_HPP

#include "conversion.hpp"

#include <format>

namespace svglib
{
	enum class ColorName : std::uint32_t
	{
		alice_blue = 0xF0F8FF,			/*!< rgb( 240, 248, 255 ) */
		antique_white = 0xFAEBD7,		/*!< rgb( 250, 235, 215 ) */
		aqua = 0x00FFFF,				/*!< rgb(   0, 255, 255 ) */
		aquamarine = 0x7FFFD4,			/*!< rgb( 127, 255, 212 ) */
		azure = 0xF0FFFF,				/*!< rgb( 240, 255, 255 ) */
		beige = 0xF5F5DC,				/*!< rgb( 245, 245, 220 ) */
		bisque = 0xFFE4C4,				/*!< rgb( 255, 228, 196 ) */
		black = 0x000000,				/*!< rgb(   0,   0,   0 ) */
		blanched_almond = 0xFFEBCD,		/*!< rgb( 255, 235, 205 ) */
		blue = 0x0000FF,				/*!< rgb(   0,   0, 255 ) */
		blue_violet = 0x8A2BE2,			/*!< rgb( 138,  43, 226 ) */
		brown = 0xA52A2A,				/*!< rgb( 165,  42,  42 ) */
		burly_wood = 0xDEB887,			/*!< rgb( 222, 184, 135 ) */
		/* ... */
		white = 0xFFFFFF,				/*!< rgb( 255, 255, 255 ) */
	};

	inline std::string_view to_string( const ColorName name )
	{
		switch( name )
		{
		case ColorName::alice_blue: return "alice blue";
		case ColorName::antique_white: return "antique white";
		case ColorName::aqua: return "aqua";
		case ColorName::aquamarine: return "aquamarine";
		case ColorName::azure: return "azure";
		case ColorName::beige: return "beige";
		case ColorName::bisque: return "bisque";
		case ColorName::black: return "black";
		case ColorName::blanched_almond: return "blanched almond";
		case ColorName::blue: return "blue";
		case ColorName::blue_violet: return "blue violet";
		case ColorName::brown: return "brown";
		case ColorName::burly_wood: return "burly wood";
		case ColorName::white: return "white";
		default: return "";
		}
	}

	/**
	 * \brief This is a RGB color.
	 */
	class Color final
	{
	public:
		constexpr Color() = delete;

		constexpr Color( const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue )
		: red_ { red }
		, green_ { green }
		, blue_ { blue }
		{}

		constexpr explicit Color( const ColorName color )
		{
			red_ = static_cast< std::uint32_t >( color ) >> 16 & 0xFF;
			green_ = static_cast< std::uint32_t >( color ) >> 8 & 0xFF;
			blue_ = static_cast< std::uint32_t >( color ) & 0xFF;
		}

		constexpr ~Color() = default;

		[[nodiscard]] constexpr auto red() const -> std::uint8_t;

		[[nodiscard]] constexpr auto green() const -> std::uint8_t;

		[[nodiscard]] constexpr auto blue() const -> std::uint8_t;

		[[nodiscard]] explicit constexpr operator std::uint32_t() const
		{
			//int result = 0;
			//result = red_ << 16;
			//result += green_ << 8;
			//result += blue_;
			//return result;

			return ( red_ << 16 ) + ( green_ << 8 ) + blue_;
		}

	private:
		std::uint8_t red_;
		std::uint8_t green_;
		std::uint8_t blue_;
	};

	constexpr auto Color::red() const -> std::uint8_t
	{
		return red_;
	}

	constexpr auto Color::green() const -> std::uint8_t
	{
		return green_;
	}

	constexpr auto Color::blue() const -> std::uint8_t
	{
		return blue_;
	}

	constexpr Color from_hex( std::string_view hex )
	{
		if( hex.length() != 6 ) throw std::logic_error( "hex must be 6 characters long" );

		return svglib::Color {
			conversion::hex_string_to_u8( hex.substr( 0, 2 ) ),
				conversion::hex_string_to_u8( hex.substr( 2, 2 ) ),
				conversion::hex_string_to_u8( hex.substr( 4, 2 ) )
		};
	}

	constexpr const char* to_hex( const svglib::Color& color )
	{
		const auto red = conversion::u8_to_hex_string( color.red() );
		const auto green = conversion::u8_to_hex_string( color.green() );
		const auto blue = conversion::u8_to_hex_string( color.blue() );

		return new char[7] { red[0], red[1], green[0], green[1], blue[0], blue[1], '\0' };
	}
}

template <>
struct std::formatter<svglib::Color>
{
	constexpr auto parse( std::format_parse_context& context )
	{
		return context.end();
	}

	auto format( const svglib::Color& color, std::format_context& context ) const
	{
		const auto value = static_cast< std::uint32_t >( color );
		const auto name = svglib::to_string( static_cast< svglib::ColorName >( value ) );

		if( name.empty() )
			//return std::format_to( context.out(), "rgb({},{},{})", color.red(), color.green(), color.blue() );
			return std::format_to( context.out(), "#{}", to_hex( color ) );
		else
			return std::format_to( context.out(), "{}", name );
	}
};

#endif