#include "svglib.hpp"

#include <iostream>

using namespace svglib;

auto main() -> int
{
    //constexpr auto color = Color( 211, 211, 211 );
    constexpr auto alice_blue = Color( ColorName::alice_blue );
    std::cout << "color=\"" << alice_blue.serialize() << "\"" << std::endl;
    std::cout << std::format( "rgb( {}, {}, {} )", alice_blue.red(), alice_blue.green(), alice_blue.blue() ) << std::endl;

    using svglib::from_hex;
    constexpr auto color = from_hex( "0077FF" );
    std::cout << "color=\"" << color.serialize() << "\"" << std::endl;

    const auto black_stroke = Stroke( Color( ColorName::black ), 1.1, Opacity( 50 , OpacityUnit::percentage ) );
    std::cout << black_stroke.serialize() << std::endl;

    return 0;

    const  auto hex = to_hex( color );
    std::cout << hex << std::endl;

    std::cout << std::format( "color=\"{}\"", color) << std::endl;
    std::cout << std::format( "color=\"{}\"", Color( ColorName::brown ) ) << std::endl;

    constexpr auto start_point = Point( 10.0, 10.0 );
    std::cout << std::format( "point( {}, {} )", start_point.x(), start_point.y() ) << std::endl;
    constexpr auto end_point = Point( 10.0, 10.0 );
    std::cout << std::format( "point( {}, {} )", end_point.x(), end_point.y() ) << std::endl;

    const  auto test = start_point.serialize();
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