#include "svglib.hpp"

#include <iostream>
#include <format>

auto main() -> int
{
    using namespace svglib;

    //constexpr auto color = svglib::Color( 211, 211, 211 );
    //constexpr auto color = svglib::Color( svglib::ColorName::alice_blue );
    //std::cout << std::format( "rgb( {}, {}, {} )", color.red(), color.green(), color.blue() ) << std::endl;

    constexpr auto color = from_hex( "0077FF" );
    const auto hex = to_hex( color );
    std::cout << hex << std::endl;

    return EXIT_SUCCESS;
}