//
// Created by claiff on 14.05.22.
//

#include "animate_rectangle_shape.hpp"
#include "utils/timer_policy.hpp"

namespace entity::decorator
{
	AnimateRectangleShape::AnimateRectangleShape( utils::types::RegistratorPtr < sf::Sprite > const& sprites_set,
												  unsigned int reload_ms )
			: mSpritesSet( sprites_set )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( reload_ms ))
	{
		//ApplyNewView();
	}

	void AnimateRectangleShape::Fire()
	{
		mBase->Fire();
	}

	void AnimateRectangleShape::Update()
	{
		if( mTimerPolicy->IsTime())
		{
			ApplyNewView();
		}
		mBase->Update();
	}

	void AnimateRectangleShape::ApplyNewView()
	{
		auto sprite = mSpritesSet->Get();

		//view.setTexture( sprite.getTexture());
		//view.setTextureRect( sprite.getTextureRect());
	}

	void AnimateRectangleShape::StartMove( types::Direction direction )
	{
		mBase->StartMove( direction );
	}

	void AnimateRectangleShape::StopMove( types::Direction direction )
	{
		mBase->StopMove( direction );
	}

	void AnimateRectangleShape::draw( sf::RenderTarget& target, const sf::RenderStates& states ) const
	{
		mBase->draw( target, states );
	}
}