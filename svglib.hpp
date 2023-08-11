//
//  svglib.hpp

#ifndef SVGLIB_HPP
#define SVGLIB_HPP

#include <string>

namespace svglib
{
    enum class ColorName : std::uint32_t
    {
        alice_blue = 0xF0F8FF,	/* rgb( 240, 248, 255) */
        /* ... */
        black = 0x000000,		/* rgb(   0,   0,   0) */
        /* ... */
        white = 0xFFFFFF		/* rgb( 255, 255, 255) */
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

        constexpr explicit Color( ColorName color )
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