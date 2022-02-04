//
// Created by claif on 22.01.2022.
//

#include "itank.hpp"

namespace tank::types
{
	sf::Sprite& ITank::CreateAllyLightTank( DIRECTION direction, ANIMATE animate ) const noexcept
	{
		auto count_animate = static_cast<int>(ANIMATE::COUNT);
		auto number = count_animate * static_cast<int>(direction) + static_cast<int>(animate);

		return mParser->GetSprite( number );
	}

	sf::Sprite& ITank::CreateAllyMiddleTank( DIRECTION direction, ANIMATE animate ) const noexcept
	{
		static int const MIDDLE_ROW = 1;
		auto count_animate = static_cast<int>(ANIMATE::COUNT);
		auto number = count_animate * static_cast<int>(direction) + static_cast<int>(animate) +
					  GetTanksInRow( count_animate ) * MIDDLE_ROW;

		return mParser->GetSprite( number );
	}

	sf::Sprite& ITank::CreateAllyHeavyTank( DIRECTION direction, ANIMATE animate ) const noexcept
	{
		static int const HEAVY_ROW = 2;
		auto count_animate = static_cast<int>(ANIMATE::COUNT);
		auto number = count_animate * static_cast<int>(direction) + static_cast<int>(animate) +
					  GetTanksInRow( count_animate ) * HEAVY_ROW;

		return mParser->GetSprite( number );
	}

	sf::Sprite& ITank::CreateAllyMoreHeavyTank( DIRECTION direction, ANIMATE animate ) const noexcept
	{
		static int const MORE_HEAVY_ROW = 3;
		auto count_animate = static_cast<int>(ANIMATE::COUNT);
		auto number = count_animate * static_cast<int>(direction) + static_cast<int>(animate) +
					  GetTanksInRow( count_animate ) * MORE_HEAVY_ROW;

		return mParser->GetSprite( number );
	}

	int ITank::GetTanksInRow( int count_animate ) const
	{
		return static_cast<int>(DIRECTION::COUNT) * count_animate;
	}
}