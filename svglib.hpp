//
//  svglib.hpp

#ifndef SVGLIB_HPP
#define SVGLIB_HPP

#include <string>

namespace svglib
{
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
}

#endif