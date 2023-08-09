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
}

#endif