//#include "color.hpp"
//#include "svglib.hpp"

#include <iostream>
#include <format>

auto main() -> int
{
    //using namespace svglib;

    //constexpr auto color = svglib::Color( 211, 211, 211 );
    //constexpr auto color = svglib::Color( svglib::ColorName::alice_blue );
    //std::cout << std::format( "rgb( {}, {}, {} )", color.red(), color.green(), color.blue() ) << std::endl;

    //constexpr auto color = from_hex( "0077FF" );
    //const  auto hex = to_hex( color );
    //std::cout << hex << std::endl;

    //const auto x = u8_to_hex_string( 127 );

    //std::cout << std::format( "color=\"{}\"", color) << std::endl;
    //std::cout << std::format( "color=\"{}\"", Color( ColorName::brown ) ) << std::endl;

    std::cout << std::format( "hello svglib" );

    return EXIT_SUCCESS;
}