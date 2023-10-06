//
//  opacity.hpp

#ifndef OPACITY_HPP
#define OPACITY_HPP

namespace svglib
{
	enum class OpacityUnit : std::uint8_t
	{
		number,
		percentage
	};

	class Opacity final : public Serializeable
	{
	public:
		constexpr Opacity() = delete;

		constexpr Opacity( const double& opacity, OpacityUnit unit = OpacityUnit::number )
		: opacity_ { opacity }
		, unit_ { unit }
		{}

		[[nodiscard]] constexpr std::string serialize() const override
		{
			if ( !isValid() )
				return std::string{};

			if ( unit_ == OpacityUnit::percentage )
				return std::format( "opacity=\"{:}%\"", opacity_ );

			return std::format( "opacity=\"{:.2f}\"", opacity_ );
		}

	private:
		[[nodiscard]] constexpr bool isValid() const
		{
			if ( unit_ == OpacityUnit::number )
				return opacity_ >= 0.0 and opacity_ <= 1.0 ? true : false;
			
			return opacity_ >= 0.0 and opacity_ <= 100.0 ? true : false;
		}

		double opacity_;
		OpacityUnit unit_;
	};
};

#endif