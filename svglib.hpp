//
//  svglib.hpp

#ifndef SVGLIB_HPP
#define SVGLIB_HPP

#include <array>
#include <string>
#include <string_view>
#include <stdexcept>
#include <algorithm>

namespace svglib
{
	namespace 
	{
		constexpr char to_lower( char character )
		{
		    if ( character >= 65 and character <= 90 )
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
		    const char left = static_cast<char>( number >> 4 );
		    const char right = static_cast<char>( number & 0x0f );

		    return new char[3] { hex_digits[left], hex_digits[right], '\0' };
		}

		constexpr std::uint8_t hex_char_to_u8( char character )
		{
		    character = to_lower( character );

		    if ( !is_hex_digit( character ) ) throw std::logic_error( "character must be a hexadecimal digit" );

		    return ( character >= 'a' and character <= 'f' ) ? character - 97 + 10 : character - 48;
		}

		constexpr std::uint8_t hex_string_to_u8( std::string_view hex )
		{
		    if ( hex.length() != 2 ) throw std::logic_error( "hex must be 2 characters long" );

		    const std::uint8_t first = hex_char_to_u8( hex[0] ) * 16;
		    const std::uint8_t second = hex_char_to_u8( hex[1] );

		    return first + second;
		}
	}

	enum class ColorName : std::uint32_t
	{
		alice_blue = 0xF0F8FF,      /* rgb( 240, 248, 255 ) */
		antique_white = 0xFAEBD7,   /* rgb( 250, 235, 215 ) */
		aqua = 0x00FFFF,            /* rgb(   0, 255, 255 ) */
		aquamarine = 0x7FFFD4,      /* rgb( 127, 255, 212 ) */
		azure = 0xF0FFFF,           /* rgb( 240, 255, 255 ) */
		/* ... */
		black = 0x000000,           /* rgb(   0,   0,   0 ) */
		/* ... */
		white = 0xFFFFFF            /* rgb( 255, 255, 255 ) */
	};

	/**
	 * \brief This is a RGB color.
	 */
	class Color final
	{
	public:
		constexpr Color() = delete;

		constexpr Color( const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue )
	        : red_ { red }, green_ { green }, blue_ { blue }
	    {
	    }

	    constexpr explicit Color( const ColorName color )
	    {
	        red_ = static_cast<std::uint32_t>( color ) >> 16 & 0xFF;
	        green_ = static_cast<std::uint32_t>( color ) >> 8 & 0xFF;
	        blue_ = static_cast<std::uint32_t>( color ) & 0xFF;
	    }

	    constexpr ~Color() = default;

	    [[nodiscard]] constexpr auto red() const
	    {
	        return red_;
	    }

	    [[nodiscard]] constexpr auto green() const
	    {
	        return green_;
	    }

	    [[nodiscard]] constexpr auto blue() const
	    {
	        return blue_;
	    }

	private:
	    std::uint8_t red_;
	    std::uint8_t green_;
	    std::uint8_t blue_;
	};

    constexpr Color from_hex( std::string_view hex )
    {
        if ( hex.length() != 6 ) throw std::logic_error( "hex must be 6 characters long" );

        return Color {
            hex_string_to_u8( hex.substr( 0, 2) ),
            hex_string_to_u8( hex.substr( 2, 2) ),
            hex_string_to_u8( hex.substr( 4, 2) )
        };
    }

    constexpr const char* to_hex( const Color& color )
    {
        const auto red = u8_to_hex_string( color.red() );
        const auto green = u8_to_hex_string( color.green() );
        const auto blue = u8_to_hex_string( color.blue() );

        return new char[7] { red[0], red[1], green[0], green[1], blue[0], blue[1], '\0' };
    }

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