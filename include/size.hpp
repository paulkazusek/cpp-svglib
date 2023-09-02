//
//  color.hpp

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
}
#endif