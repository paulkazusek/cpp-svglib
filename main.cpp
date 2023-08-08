#include "svglib.hpp"

#include <iostream>
#include <format>

auto main() -> void
{
    constexpr auto color = svglib::Color( 211, 211, 211 );
    std::cout << std::format( "rgb( {}, {}, {} )", color.red(), color.green(), color.blue() ) << std::endl;
}