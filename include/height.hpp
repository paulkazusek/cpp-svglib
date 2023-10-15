//
//  height.hpp

#ifndef HEIGHT_HPP
#define HEIGHT_HPP

#include "unit.hpp"

namespace svglib
{
	class Height final : public Serializeable
	{
	public:
		constexpr Height() = delete;

		explicit constexpr Height( const double& height, const Unit unit = Unit::number )
		: height_ { height }
		, unit_ { unit }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			if ( unit_ == Unit::percentage )
				return std::format( "height=\"{:}%\"", height_ );

			return std::format( "height=\"{:.2f}\"", height_ );
		}

	private:
		double height_;
		Unit unit_;
	};
};

#endif