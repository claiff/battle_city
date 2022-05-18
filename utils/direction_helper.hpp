//
// Created by claiff on 17.05.22.
//


#pragma once

#include <SFML/include/SFML/System/Angle.hpp>

#include "entity/types/ientity.hpp"

namespace utils
{
	class DirectionHelper
	{
	public:
		static constexpr int ZERO_STEP = 0;

		static sf::Angle DirectionToAngle( entity::types::Direction direction );
		static entity::types::Direction AngleToDirection( sf::Angle angle );
		static sf::Vector2f StepOnDirection( entity::types::Direction direction, float step, float zero_step = ZERO_STEP );
	private:
		DirectionHelper() = default;
		~DirectionHelper() = default;
	};
} // utils
