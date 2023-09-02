#include "color.hpp"
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

    return EXIT_SUCCESS;
}