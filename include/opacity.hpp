//
//  opacity.hpp

#ifndef SVGLIB_OPACITY_HPP
#define SVGLIB_OPACITY_HPP

#include "unit.hpp"

namespace svglib
{
	class Opacity final : public Serializeable
	{
	public:
		constexpr Opacity() = delete;

		/**
		 * \brief
		 *
		 * \param opacity decimal value ranging from 0.0 to 1.0 or percentage from 0.0% to 100.0% at which we want to set the opacity of the element 
		 * \param unit decimal number or percentage value
		 */
		explicit constexpr Opacity( const double& opacity, const UnitType unit = UnitType::user )
			: opacity_ { opacity }
			, unit_ { unit }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			if ( !isValid() )
				return std::string{};

			if  ( unit_ == UnitType::percentage )
				return std::format( "opacity=\"{:}%\"", opacity_ );

			return std::format( "opacity=\"{:.2f}\"", opacity_ );
		}

	private:
		[[nodiscard]] constexpr bool isValid() const
		{
			if ( unit_ == UnitType::none )
				return opacity_ >= 0.0 and opacity_ <= 1.0 ? true : false;
			
			return opacity_ >= 0.0 and opacity_ <= 100.0 ? true : false;
		}

		double opacity_;
		UnitType unit_;
	};
}

#endif