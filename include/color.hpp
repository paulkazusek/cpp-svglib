//
//  color.hpp

#ifndef SVGLIB_COLOR_HPP
#define SVGLIB_COLOR_HPP

#include "conversion.hpp"
#include "serializeable.hpp"

#include <format>

namespace svglib
{
	enum class ColorName : std::uint32_t
	{
		alice_blue = 0xF0F8FF,				/*!< rgb( 240, 248, 255 ) */
		antique_white = 0xFAEBD7,			/*!< rgb( 250, 235, 215 ) */
		aqua = 0x00FFFF,					/*!< rgb(   0, 255, 255 ) */
		aquamarine = 0x7FFFD4,				/*!< rgb( 127, 255, 212 ) */
		azure = 0xF0FFFF,					/*!< rgb( 240, 255, 255 ) */
		beige = 0xF5F5DC,					/*!< rgb( 245, 245, 220 ) */
		bisque = 0xFFE4C4,					/*!< rgb( 255, 228, 196 ) */
		black = 0x000000,					/*!< rgb(   0,   0,   0 ) */
		blanched_almond = 0xFFEBCD,			/*!< rgb( 255, 235, 205 ) */
		blue = 0x0000FF,					/*!< rgb(   0,   0, 255 ) */
		blue_violet = 0x8A2BE2,				/*!< rgb( 138,  43, 226 ) */
		brown = 0xA52A2A,					/*!< rgb( 165,  42,  42 ) */
		burly_wood = 0xDEB887,				/*!< rgb( 222, 184, 135 ) */
		cadet_blue = 0x5F9EA0,				/*!< rgb(  95, 158, 160 ) */
		chartreuse = 0x7FFF00,				/*!< rgb( 127, 255,   0 ) */
		chocolate = 0xD2691E,				/*!< rgb( 210, 105,  30 ) */
		coral = 0xFF7F50,					/*!< rgb( 255, 127,  80 ) */
		cornflower_blue = 0x6495ED,			/*!< rgb( 100, 149, 237 ) */
		cornsilk = 0xFFF8DC,				/*!< rgb( 255, 248, 220 ) */
		crimson = 0xDC143C,					/*!< rgb( 220,  20,  60 ) */
		cyan = 0x00FFFF,					/*!< rgb(   0, 255, 255 ) */
		dark_blue = 0x00008B,				/*!< rgb(   0,   0, 139 ) */
		dark_cyan = 0x008B8B,				/*!< rgb(   0, 139, 139 ) */
		dark_golden_rod = 0xB8860B,			/*!< rgb( 184, 134,  11 ) */
		dark_gray = 0xA9A9A9,				/*!< rgb( 169, 169, 169 ) */
		dark_green = 0x006400,				/*!< rgb(   0, 100,   0 ) */
		dark_khaki = 0xBDB76B,				/*!< rgb( 189, 183, 107 ) */
		dark_magenta = 0x8B008B,			/*!< rgb( 139,   0, 139 ) */
		dark_olive_green = 0x556B2F,		/*!< rgb(  85, 107,  47 ) */
		dark_orange = 0xFF8C00,				/*!< rgb( 255, 140,   0 ) */
		dark_orchid = 0x9932CC,				/*!< rgb( 153,  50, 204 ) */
		dark_red = 0x8B0000,				/*!< rgb( 139,   0,   0 ) */
		dark_salmon = 0xE9967A,				/*!< rgb( 233, 150, 122 ) */
		dark_sea_green = 0x8FBC8F,			/*!< rgb( 143, 188, 143 ) */
		dark_slate_blue = 0x483D8B,			/*!< rgb(  72,  61, 139 ) */
		dark_slate_gray = 0x2F4F4F,			/*!< rgb(  47,  79,  79 ) */
		dark_turquoise = 0x00CED1,			/*!< rgb(   0, 206, 209 ) */
		dark_violet = 0x9400D3,				/*!< rgb( 148,   0, 211 ) */
		deep_pink = 0xFF1493,				/*!< rgb( 255,  20, 147 ) */
		deep_sky_blue = 0x00BFFF,			/*!< rgb(   0, 191, 255 ) */
		dim_gray = 0x696969,				/*!< rgb( 105, 105, 105 ) */
		dodger_blue = 0x1E90FF,				/*!< rgb(  30, 144, 255 ) */
		fire_brick = 0xB22222,				/*!< rgb( 178,  34,  34 ) */
		floral_white = 0xFFFAF0,			/*!< rgb( 255, 250, 240 ) */
		forest_green = 0x228B22,			/*!< rgb(  34, 139,  34 ) */
		fuchsia = 0xFF00FF,					/*!< rgb( 255,   0, 255 ) */
		gainsboro = 0xDCDCDC,				/*!< rgb( 220, 220, 220 ) */
		ghost_white = 0xF8F8FF,				/*!< rgb( 248, 248, 255 ) */
		gold = 0xFFD700,					/*!< rgb( 255, 215,   0 ) */
		golden_rod = 0xDAA520,				/*!< rgb( 218, 165,  32 ) */
		gray = 0x808080,					/*!< rgb( 128, 128, 128 ) */
		green = 0x008000,					/*!< rgb(   0, 128,   0 ) */
		green_yellow = 0xADFF2F,			/*!< rgb( 173, 255,  47 ) */
		honey_dew = 0xF0FFF0,				/*!< rgb( 240, 255, 240 ) */
		hot_pink = 0xFF69B4,				/*!< rgb( 255, 105, 180 ) */
		indian_red = 0xCD5C5C,				/*!< rgb( 205,  92,  92 ) */
		indigo = 0x4B0082,					/*!< rgb(  75,   0, 130 ) */
		ivory = 0xFFFFF0,					/*!< rgb( 255, 255, 240 ) */
		khaki = 0xF0E68C,					/*!< rgb( 240, 230, 140 ) */
		lavender = 0xE6E6FA,				/*!< rgb( 230, 230, 250 ) */
		lavender_blush = 0xFFF0F5,			/*!< rgb( 255, 240, 245 ) */
		lawn_green = 0x7CFC00,				/*!< rgb( 124, 252,   0 ) */
		lemon_chiffon = 0xFFFACD,			/*!< rgb( 255, 250, 205 ) */
		light_blue = 0xADD8E6,				/*!< rgb( 173, 216, 230 ) */
		light_coral = 0xF08080,				/*!< rgb( 240, 128, 128 ) */
		light_cyan = 0xE0FFFF,				/*!< rgb( 224, 255, 255 ) */
		light_golden_rod_yellow = 0xFAFAD2,	/*!< rgb( 250, 250, 210 ) */
		light_gray = 0xD3D3D3,				/*!< rgb( 211, 211, 211 ) */
		light_green = 0x90EE90,				/*!< rgb( 144, 238, 144 ) */
		light_pink = 0xFFB6C1,				/*!< rgb( 255, 182, 193 ) */
		light_salmon = 0xFFA07A,			/*!< rgb( 255, 160, 122 ) */
		light_sea_green = 0x20B2AA,			/*!< rgb(  32, 178, 170 ) */
		light_sky_blue = 0x87CEFA,			/*!< rgb( 135, 206, 250 ) */
		light_slate_gray = 0x778899,		/*!< rgb( 119, 136, 153 ) */
		light_steel_blue = 0xB0C4DE,		/*!< rgb( 176, 196, 222 ) */
		light_yellow = 0xFFFFE0,			/*!< rgb( 255, 255, 224 ) */
		lime = 0x00FF00,					/*!< rgb(   0, 255,   0 ) */
		lime_green = 0x32CD32,				/*!< rgb(  50, 205,  50 ) */
		linen = 0xFAF0E6,					/*!< rgb( 250, 240, 230 ) */
		maroon = 0x800000,					/*!< rgb( 128,   0,   0 ) */
		magenta = 0xFF00FF,					/*!< rgb( 255,   0, 255 ) */
		medium_aquamarine = 0x66CDAA,		/*!< rgb( 102, 205, 170 ) */
		medium_blue = 0x0000CD,				/*!< rgb(   0,   0, 205 ) */
		medium_orchid = 0xBA55D3,			/*!< rgb( 186,  85, 211 ) */
		medium_purple = 0x9370DB,			/*!< rgb( 147, 112, 219 ) */
		medium_sea_green = 0x3CB371,		/*!< rgb(  60, 179, 113 ) */
		medium_slate_blue = 0x7B68EE,		/*!< rgb( 123, 104, 238 ) */
		medium_spring_green = 0x00FA9A,		/*!< rgb(   0, 250, 154 ) */
		medium_turquoise = 0x48D1CC,		/*!< rgb(  72, 209, 204 ) */
		medium_violet_red = 0xC71585,		/*!< rgb( 199,  21, 133 ) */
		midnight_blue = 0x191970,			/*!< rgb(  25,  25, 112 ) */
		mint_cream = 0xF5FFFA,				/*!< rgb( 245, 255, 250 ) */
		misty_rose = 0xFFE4E1,				/*!< rgb( 255, 228, 225 ) */
		moccasin = 0xFFE4B5,				/*!< rgb( 255, 228, 181 ) */
		navajo_white = 0xFFDEAD,			/*!< rgb( 255, 222, 173 ) */
		navy = 0x000080,					/*!< rgb(   0,   0, 128 ) */
		old_lace = 0xFDF5E6,				/*!< rgb( 253, 245, 230 ) */
		olive = 0x808000,					/*!< rgb( 128, 128,   0 ) */
		olive_drab = 0x6B8E23,				/*!< rgb( 107, 142,  35 ) */
		orange = 0xFFA500,					/*!< rgb( 255, 165,   0 ) */
		orange_red = 0xFF4500,				/*!< rgb( 255,  69,   0 ) */
		orchid = 0xDA70D6,					/*!< rgb( 218, 112, 214 ) */
		pale_golden_rod = 0xEEE8AA,			/*!< rgb( 238, 232, 170 ) */
		pale_green = 0x98FB98,				/*!< rgb( 152, 251, 152 ) */
		pale_turquoise = 0xAFEEEE,			/*!< rgb( 175, 238, 238 ) */
		pale_violet_red = 0xDB7093,			/*!< rgb( 219, 112, 147 ) */
		papaya_whip = 0xFFEFD5,				/*!< rgb( 255, 239, 213 ) */
		peach_puff = 0xFFDAB9,				/*!< rgb( 255, 218, 185 ) */
		peru = 0xCD853F,					/*!< rgb( 205, 133,  63 ) */
		pink = 0xFFC0CB,					/*!< rgb( 255, 192, 203 ) */
		plum = 0xDDA0DD,					/*!< rgb( 221, 160, 221 ) */
		powder_blue = 0xB0E0E6,				/*!< rgb( 176, 224, 230 ) */
		purple = 0x800080,					/*!< rgb( 128,   0, 128 ) */
		rebecca_purple = 0x663399,			/*!< rgb( 102,  51, 153 ) */
		red = 0xFF0000,						/*!< rgb( 255,   0,   0 ) */
		rosy_brown = 0xBC8F8F,				/*!< rgb( 188, 143, 143 ) */
		royal_blue = 0x4169E1,				/*!< rgb(  65, 105, 225 ) */
		saddle_brown = 0x8B4513,			/*!< rgb( 139,  69,  19 ) */
		salmon = 0xFA8072,					/*!< rgb( 250, 128, 114 ) */
		sandy_brown = 0xF4A460,				/*!< rgb( 244, 164,  96 ) */
		sea_green = 0x2E8B57,				/*!< rgb(  46, 139,  87 ) */
		sea_shell = 0xFFF5EE,				/*!< rgb( 255, 245, 238 ) */
		sienna = 0xA0522D,					/*!< rgb( 160,  82,  45 ) */
		silver = 0xC0C0C0,					/*!< rgb( 192, 192, 192 ) */
		sky_blue = 0x87CEEB,				/*!< rgb( 135, 206, 235 ) */
		slate_blue = 0x6A5ACD,				/*!< rgb( 106,  90, 205 ) */
		slate_gray = 0x708090,				/*!< rgb( 112, 128, 144 ) */
		snow = 0xFFFAFA,					/*!< rgb( 255, 250, 250 ) */
		spring_green = 0x00FF7F,			/*!< rgb(   0, 255, 127 ) */
		steel_blue = 0x4682B4,				/*!< rgb(  70, 130, 180 ) */
		tan = 0xD2B48C,						/*!< rgb( 210, 180, 140 ) */
		teal = 0x008080,					/*!< rgb(   0, 128, 128 ) */
		thistle = 0xD8BFD8,					/*!< rgb( 216, 191, 216 ) */
		tomato = 0xFF6347,					/*!< rgb( 255,  99,  71 ) */
		turquoise = 0x40E0D0,				/*!< rgb(  64, 224, 208 ) */
		violet = 0xEE82EE,					/*!< rgb( 238, 130, 238 ) */
		wheat = 0xF5DEB3,					/*!< rgb( 245, 222, 179 ) */
		white = 0xFFFFFF,					/*!< rgb( 255, 255, 255 ) */
		white_smoke = 0xF5F5F5,				/*!< rgb( 245, 245, 245 ) */
		yellow = 0xFFFF00,					/*!< rgb( 255, 255,   0 ) */
		yellow_green = 0x9ACD32				/*!< rgb( 154, 205,  50 ) */
	};

	inline std::string_view to_string( const ColorName name )
	{
		switch( name )
		{
		case ColorName::alice_blue: return "aliceblue";
		case ColorName::antique_white: return "antiquewhite";
		case ColorName::aqua: return "aqua";
		case ColorName::aquamarine: return "aquamarine";
		case ColorName::azure: return "azure";
		case ColorName::beige: return "beige";
		case ColorName::bisque: return "bisque";
		case ColorName::black: return "black";
		case ColorName::blanched_almond: return "blanchedalmond";
		case ColorName::blue: return "blue";
		case ColorName::blue_violet: return "blueviolet";
		case ColorName::brown: return "brown";
		case ColorName::burly_wood: return "burlywood";
		case ColorName::cadet_blue: return "cadetblue";
		case ColorName::chartreuse: return "chartreuse";
		case ColorName::chocolate: return "chocolate";
		case ColorName::coral: return "coral";
		case ColorName::cornflower_blue: return "cornflowerblue";
		case ColorName::cornsilk: return "cornsilk";
		case ColorName::crimson: return "crimson";
		case ColorName::dark_blue: return "darkblue";
		case ColorName::dark_cyan: return "darkcyan";
		case ColorName::dark_golden_rod: return "darkgoldenrod";
		case ColorName::dark_gray: return "darkgray";
		case ColorName::dark_green: return "darkgreen";
		case ColorName::dark_khaki: return "darkkhaki";
		case ColorName::dark_magenta: return "darkmagenta";
		case ColorName::dark_olive_green: return "darkolivegreen";
		case ColorName::dark_orange: return "darkorange";
		case ColorName::dark_orchid: return "darkorchid";
		case ColorName::dark_red: return "darkred";
		case ColorName::dark_salmon: return "darksalmon";
		case ColorName::dark_sea_green: return "darkseagreen";
		case ColorName::dark_slate_blue: return "darkslateblue";
		case ColorName::dark_slate_gray: return "darkslategray";
		case ColorName::dark_turquoise: return "darkturquoise";
		case ColorName::dark_violet: return "darkviolet";
		case ColorName::deep_pink: return "deeppink";
		case ColorName::deep_sky_blue: return "deepskyblue";
		case ColorName::dim_gray: return "dimgray";
		case ColorName::dodger_blue: return "dodgerblue";
		case ColorName::fire_brick: return "firebrick";
		case ColorName::floral_white: return "floralwhite";
		case ColorName::forest_green: return "forestgreen";
		case ColorName::fuchsia: return "fuchsia";
		case ColorName::gainsboro: return "gainsboro";
		case ColorName::ghost_white: return "ghostwhite";
		case ColorName::gold: return "gold";
		case ColorName::golden_rod: return "goldenrod";
		case ColorName::gray: return "gray";
		case ColorName::green: return "green";
		case ColorName::green_yellow: return "greenyellow";
		case ColorName::honey_dew: return "honeydew";
		case ColorName::hot_pink: return "hotpink";
		case ColorName::indian_red: return "indianred";
		case ColorName::indigo: return "indigo";
		case ColorName::ivory: return "ivory";
		case ColorName::khaki: return "khaki";
		case ColorName::lavender: return "lavender";
		case ColorName::lavender_blush: return "lavenderblush";
		case ColorName::lawn_green: return "lawngreen";
		case ColorName::lemon_chiffon: return "lemonchiffon";
		case ColorName::light_blue: return "lightblue";
		case ColorName::light_coral: return "lightcoral";
		case ColorName::light_cyan: return "lightcyan";
		case ColorName::light_golden_rod_yellow: return "lightgoldenrodyellow";
		case ColorName::light_gray: return "lightgray";
		case ColorName::light_green: return "lightgreen";
		case ColorName::light_pink: return "lightpink";
		case ColorName::light_salmon: return "lightsalmon";
		case ColorName::light_sea_green: return "lightseagreen";
		case ColorName::light_sky_blue: return "lightskyblue";
		case ColorName::light_slate_gray: return "lightslategray";
		case ColorName::light_steel_blue: return "lightsteelblue";
		case ColorName::light_yellow: return "lightyellow";
		case ColorName::lime: return "lime";
		case ColorName::lime_green: return "limegreen";
		case ColorName::linen: return "linen";
		case ColorName::maroon: return "maroon";
		/*case ColorName::magenta: return "magenta";*/
		case ColorName::medium_aquamarine: return "mediumaquamarine";
		case ColorName::medium_blue: return "mediumblue";
		case ColorName::medium_orchid: return "mediumorchid";
		case ColorName::medium_purple: return "mediumpurple";
		case ColorName::medium_sea_green: return "mediumseagreen";
		case ColorName::medium_slate_blue: return "mediumslateblue";
		case ColorName::medium_spring_green: return "mediumspringgreen";
		case ColorName::medium_turquoise: return "mediumturquoise";
		case ColorName::medium_violet_red: return "mediumvioletred";
		case ColorName::midnight_blue: return "midnightblue";
		case ColorName::mint_cream: return "mintcream";
		case ColorName::misty_rose: return "mistyrose";
		case ColorName::moccasin: return "moccasin";
		case ColorName::navajo_white: return "navajowhite";
		case ColorName::navy: return "navy";
		case ColorName::old_lace: return "oldlace";
		case ColorName::olive: return "olive";
		case ColorName::olive_drab: return "olivedrab";
		case ColorName::orange: return "orange";
		case ColorName::orange_red: return "orangered";
		case ColorName::orchid: return "orchid";
		case ColorName::pale_golden_rod: return "palegoldenrod";
		case ColorName::pale_green: return "palegreen";
		case ColorName::pale_turquoise: return "paleturquoise";
		case ColorName::pale_violet_red: return "palevioletred";
		case ColorName::papaya_whip: return "papayawhip";
		case ColorName::peach_puff: return "peachpuff";
		case ColorName::peru: return "peru";
		case ColorName::pink: return "pink";
		case ColorName::plum: return "plum";
		case ColorName::powder_blue: return "powderblue";
		case ColorName::purple: return "purple";
		case ColorName::rebecca_purple: return "rebeccapurple";
		case ColorName::red: return "red";
		case ColorName::rosy_brown: return "rosybrown";
		case ColorName::royal_blue: return "royalblue";
		case ColorName::saddle_brown: return "saddlebrown";
		case ColorName::salmon: return "salmon";
		case ColorName::sandy_brown: return "sandybrown";
		case ColorName::sea_green: return "seagreen";
		case ColorName::sea_shell: return "seashell";
		case ColorName::sienna: return "sienna";
		case ColorName::silver: return "silver";
		case ColorName::sky_blue: return "skyblue";
		case ColorName::slate_blue: return "slateblue";
		case ColorName::slate_gray: return "slategray";
		case ColorName::snow: return "snow";
		case ColorName::spring_green: return "springgreen";
		case ColorName::steel_blue: return "steelblue";
		case ColorName::tan: return "tan";
		case ColorName::teal: return "teal";
		case ColorName::thistle: return "thistle";
		case ColorName::tomato: return "tomato";
		case ColorName::turquoise: return "turquoise";
		case ColorName::violet: return "violet";
		case ColorName::wheat: return "wheat";
		case ColorName::white: return "white";
		case ColorName::white_smoke: return "white_smoke";
		case ColorName::yellow: return "yellow";
		case ColorName::yellow_green: return "yellowgreen";
		default: return "";
		}
	}

	/**
	 * \brief This is a RGB color.
	 */
	class Color final : public Serializeable
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

		[[nodiscard]] /*constexpr*/ std::string serialize() const override;

	private:
		std::uint8_t red_;
		std::uint8_t green_;
		std::uint8_t blue_;
	};

	// Color constants
	inline constexpr Color black { ColorName::black };

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

	/*constexpr*/
	inline auto Color::serialize() const -> std::string
	{
		return std::format( "{}", *this );
	}

	constexpr Color from_hex( std::string_view hex )
	{
		if( hex.length() != 6 ) throw std::logic_error( "hex must be 6 characters long" );

		return Color {
			conversion::hex_string_to_u8( hex.substr( 0, 2 ) ),
				conversion::hex_string_to_u8( hex.substr( 2, 2 ) ),
				conversion::hex_string_to_u8( hex.substr( 4, 2 ) )
		};
	}

	constexpr const char* to_hex( const Color& color )
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
			return std::format_to( context.out(), "#{}", to_hex( color ) );
		
		return std::format_to( context.out(), "{}", name );
	}
};

#endif