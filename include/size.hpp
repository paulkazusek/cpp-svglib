//
//  size.hpp

#ifndef SIZE_HPP
#define SIZE_HPP

namespace svglib
{
	/**
	 * \brief
	 */
	class Size final
	{
	public:
		constexpr Size() = delete;

		constexpr Size( const double& width, const double& height )
			: width_ { width }
			, height_ { height }
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

	constexpr Size screen_4k { 4096, 2160 };
	constexpr Size screen_ultra_hd { 3840, 2160 };
	constexpr Size screen_ultra_wide { 3840, 1080 };
	constexpr Size screen_full_hd { 1920, 1080 };
	constexpr Size screen_hd { 1280, 720 };

	/**
	The ideal size for square posts is 1080px by 1080px at a 1:1 aspect ratio.
	*/
	constexpr Size instagram_post_size_square { 1080, 1080 };

	/**
	 The ideal size for landscape  posts is 1080px by 566px at a 1.91:1 aspect ratio.
	 */
	constexpr Size instagram_post_size_landscape { 1080, 566 };

	/**
	 The ideal size for vertical posts is 1080px by 1350px at a 4:5 aspect ratio.
	 */
	constexpr Size instagram_post_size_vertical { 1080, 1350 };
}
#endif