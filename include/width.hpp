//
//  width.hpp

#ifndef WIDTH_HPP
#define WIDTH_HPP

#include "unit.hpp"

namespace svglib
{
	class Width final : public Serializeable
	{
	public:
		constexpr Width() = delete;

		explicit constexpr Width( const double& width, Unit unit = Unit::number )
		: width_ { width }
		, unit_ { unit }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			if ( unit_ == Unit::percentage )
				return std::format( "width=\"{:}%\"", width_ );

			return std::format( "width=\"{:.2f}\"", width_ );
		}

	private:
		double width_;
		Unit unit_;
	};
};

#endif