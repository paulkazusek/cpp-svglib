#include "color.hpp"
#include "point.hpp"
#include "line.hpp"
#include "fill.hpp"
//#include "svglib.hpp"

#include <iostream>
//#include <format>

auto main() -> int
{
    using svglib::Color;
    using svglib::ColorName;

    //constexpr auto color = svglib::Color( 211, 211, 211 );
    constexpr auto alice_blue = Color( ColorName::alice_blue );
    std::cout << std::format( "rgb( {}, {}, {} )", alice_blue.red(), alice_blue.green(), alice_blue.blue() ) << std::endl;

    using svglib::from_hex;
    constexpr auto color = from_hex( "0077FF" );
    const  auto hex = to_hex( color );
    std::cout << hex << std::endl;

    //std::cout << std::format( "color=\"{}\"", color) << std::endl;
    //std::cout << std::format( "color=\"{}\"", Color( ColorName::brown ) ) << std::endl;

    //std::cout << std::format( "hello svglib" );

    constexpr auto start_point = svglib::Point( 10.0, 10.0 );
    std::cout << std::format( "point( {}, {} )", start_point.x(), start_point.y() ) << std::endl;
    constexpr auto end_point = svglib::Point( 10.0, 10.0 );
    std::cout << std::format( "point( {}, {} )", end_point.x(), end_point.y() ) << std::endl;

    constexpr  auto test = start_point.serialize();
	std::cout << test << std::endl;

    if constexpr (start_point == end_point )
    {
        std::cout << "start_point == end_point" << std::endl;
    }

    constexpr auto line = svglib::Line( start_point, end_point );

    constexpr auto black_color = Color( ColorName::black );
    constexpr auto black_fill = svglib::Fill( black_color );

    return EXIT_SUCCESS;
}