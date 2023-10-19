//
//  size.hpp

#ifndef SVGLIB_SIZE_HPP
#define SVGLIB_SIZE_HPP

#include "height.hpp"
#include "width.hpp"

namespace svglib
{
	//class Height;
	//class Width;
	/**
	 * \brief
	 */
	class Size final : public Serializeable
	{
	public:
		constexpr Size() = delete;

		constexpr Size( Width width, Height height )
		: width_ { std::move( width ) }
		, height_ { std::move( height ) }
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

		[[nodiscard]] /*constexpr*/ std::string serialize() const override
		{
			return std::format( "{} {}", width_.serialize(), height_.serialize() );
		}

	private:
		Width width_;
		Height height_;
	};

	constexpr Size screen_4k { Width( 4096 ), Height( 2160 ) };
	constexpr Size screen_ultra_hd { Width( 3840 ), Height( 2160 ) };
	constexpr Size screen_ultra_wide { Width( 3840 ), Height( 1080 ) };
	constexpr Size screen_full_hd { Width( 1920 ), Height( 1080 ) };
	constexpr Size screen_hd { Width( 1280 ), Height( 720 ) };

	/**
	The ideal size for square posts is 1080px by 1080px at a 1:1 aspect ratio.
	*/
	constexpr Size instagram_post_size_square { Width( 1080 ), Height( 1080 ) };

	/**
	 The ideal size for landscape  posts is 1080px by 566px at a 1.91:1 aspect ratio.
	 */
	constexpr Size instagram_post_size_landscape { Width( 1080 ), Height( 566 ) };

	/**
	 The ideal size for vertical posts is 1080px by 1350px at a 4:5 aspect ratio.
	 */
	constexpr Size instagram_post_size_vertical { Width( 1080 ), Height( 1350 ) };
}

#endif