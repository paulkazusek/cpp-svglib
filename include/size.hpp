//
//  size.hpp

#ifndef SVGLIB_SIZE_HPP
#define SVGLIB_SIZE_HPP

#include "unit.hpp"

namespace svglib
{
	/**
	 * \brief
	 */
	class Size final : public Serializeable
	{
	public:
		constexpr Size() = delete;

		constexpr Size( const Unit& width, const Unit& height )
			: width_ { width }
			, height_ { height }
		{}

		constexpr ~Size() override = default;

		[[nodiscard]]
		constexpr auto width() const
		{
			return width_;
		}

		[[nodiscard]]
		constexpr auto height() const
		{
			return height_;
		}

		[[nodiscard]] auto serialize() const -> std::string override
		{
			return std::format( "{} {}", width_, height_ );
		}

	private:
		Unit width_;
		Unit height_;
	};

	constexpr Size screen_4k {4096_px, 2160_px };
	constexpr Size screen_ultra_hd { 3840_px, 2160_px };
	constexpr Size screen_ultra_wide { 3840_px, 1080_px };
	constexpr Size screen_full_hd { 1920_px, 1080_px };
	constexpr Size screen_hd { 1280_px, 720_px };

	/**
	The ideal size for square posts is 1080px by 1080px at a 1:1 aspect ratio.
	*/
	constexpr Size instagram_post_size_square { 1080_px, 1080_px };

	/**
	 The ideal size for landscape  posts is 1080px by 566px at a 1.91:1 aspect ratio.
	 */
	constexpr Size instagram_post_size_landscape { 1080_px, 566_px };

	/**
	 The ideal size for vertical posts is 1080px by 1350px at a 4:5 aspect ratio.
	 */
	constexpr Size instagram_post_size_vertical { 1080_px, 1350_px };
}

#endif