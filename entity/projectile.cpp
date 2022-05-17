//
// Created by claiff on 17.05.22.
//

#include <SFML/Graphics/RenderTarget.hpp>

#include "projectile.hpp"
#include "utils/timer_policy.hpp"
#include "utils/direction_helper.hpp"

namespace entity
{
	Projectile::Projectile( sf::RectangleShape const& view, ProjectileInfo const& move_info )
			: mView( view )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( move_info.period_ms ))
	{
		static constexpr unsigned int ONE_STEP = 1;

		auto normal = utils::DirectionHelper::StepOnDirection( move_info.direction, ONE_STEP );
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
}