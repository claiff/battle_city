//
// Created by claif on 22.01.2022.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>

enum class DIRECTION
		: int
{
	UP = 0, LEFT, DOWN, RIGHT, COUNT = 4
};

enum class ANIMATE
		: int
{
	FIRST_SPRITE = 0, SECOND_SPRITE, COUNT = 2
};

namespace tank::types
{
	class ITank
	{
	public:
		ITank() = default;
		~ITank() = default;

		sf::Sprite& CreateAllyLightTank( DIRECTION direction, ANIMATE animate ) const noexcept;
	};
}
