#include "color.hpp"

#include <array>
#include <stdexcept>

namespace svglib
{
	namespace
	{
		constexpr char to_lower( char character )
		{
			if( character >= 65 and character <= 90 )
				character += 97 - 65;

			return character;
		}

		constexpr std::array hex_digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

		constexpr bool is_hex_digit( const char character )
		{
			return find( std::begin( hex_digits ), std::end( hex_digits ), to_lower( character ) ) != std::end( hex_digits );
		}

		constexpr const char* u8_to_hex_string( const std::uint8_t number )
		{
			const char left = static_cast< char >( number >> 4 );
			const char right = static_cast< char >( number & 0x0f );

			return new char[3] { hex_digits[left], hex_digits[right], '\0' };
		}

		constexpr std::uint8_t hex_char_to_u8( char character )
		{
			character = to_lower( character );

			if( !is_hex_digit( character ) ) throw std::logic_error( "character must be a hexadecimal digit" );

			return ( character >= 'a' and character <= 'f' ) ? character - 97 + 10 : character - 48;
		}

		constexpr std::uint8_t hex_string_to_u8( std::string_view hex )
		{
			if( hex.length() != 2 ) throw std::logic_error( "hex must be 2 characters long" );

			const std::uint8_t first = hex_char_to_u8( hex[0] ) * 16;
			const std::uint8_t second = hex_char_to_u8( hex[1] );

			return first + second;
		}
	}

	constexpr svglib::Color from_hex( std::string_view hex )
	{
		if( hex.length() != 6 ) throw std::logic_error( "hex must be 6 characters long" );

		return svglib::Color {
			hex_string_to_u8( hex.substr( 0, 2 ) ),
				hex_string_to_u8( hex.substr( 2, 2 ) ),
				hex_string_to_u8( hex.substr( 4, 2 ) )
		};
	}

	constexpr const char* to_hex( const svglib::Color& color )
	{
		const auto red = u8_to_hex_string( color.red() );
		const auto green = u8_to_hex_string( color.green() );
		const auto blue = u8_to_hex_string( color.blue() );

		return new char[7] { red[0], red[1], green[0], green[1], blue[0], blue[1], '\0' };
	}

}