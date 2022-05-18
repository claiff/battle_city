//
// Created by claiff on 17.05.22.
//

#include "direction_helper.hpp"

namespace utils
{
	sf::Angle DirectionHelper::DirectionToAngle( entity::types::Direction direction )
	{
		switch( direction )
		{
			case entity::types::Direction::Up :
				return sf::degrees( 0 );
			case entity::types::Direction::Right :
				return sf::degrees( 90 );
			case entity::types::Direction::Down :
				return sf::degrees( 180 );
			case entity::types::Direction::Left :
				return sf::degrees( 270 );
			default:
				return sf::degrees( 0 );
		}
	}

	entity::types::Direction DirectionHelper::AngleToDirection( sf::Angle angle )
	{
		switch( static_cast<int>(angle.asDegrees()))
		{
			case 0 :
				return entity::types::Direction::Up;
			case 90:
				return entity::types::Direction::Right;
			case 180:
				return entity::types::Direction::Down;
			case 270:
				return entity::types::Direction::Left;
			default:
				return entity::types::Direction::Up;
		}
	}

	sf::Vector2f DirectionHelper::StepOnDirection( entity::types::Direction direction, float step, float zero_step )
	{
		sf::Vector2f result;
		switch( direction )
		{
			case entity::types::Direction::Up:
				result = {zero_step, -step};
				break;
			case entity::types::Direction::Down:
				result = {zero_step, step};
				break;
			case entity::types::Direction::Left:
				result = {-step, zero_step};
				break;
			case entity::types::Direction::Right:
				result = {step, zero_step};
				break;
			default:
				result = {};
		}
		return result;
	}
} // utils