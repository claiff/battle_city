//
// Created by claiff on 17.05.22.
//

#include <SFML/Graphics/RenderTarget.hpp>

#include "projectile.hpp"
#include "utils/timer_policy.hpp"

namespace entity
{
	Projectile::Projectile( sf::RectangleShape const& view, ProjectileInfo const& move_info )
			: mView( view )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( move_info.period_ms ))
	{
		auto normal = ConvertDirectionToFloat( move_info.direction );
		mStepMove = {move_info.step * normal.x, move_info.step * normal.y};
	}

	void Projectile::Update()
	{
		if( mTimerPolicy->IsTime())
		{
			mView.move( mStepMove );
		}
	}

	sf::FloatRect Projectile::GetRect() const
	{
		return {mView.getPosition(), mView.getSize()};
	}

	void Projectile::draw( sf::RenderTarget& target, const sf::RenderStates& states ) const
	{
		target.draw( mView );
	}

	sf::Vector2f Projectile::ConvertDirectionToFloat( types::Direction direction ) const
	{
		switch( direction )
		{
			case types::Direction::Up:
				return {0, -1};
			case types::Direction::Down:
				return {0, 1};
			case types::Direction::Left:
				return {-1, 0};
			case types::Direction::Right:
				return {1, 0};
			default:
				return {0, 0};
		}
	}
}