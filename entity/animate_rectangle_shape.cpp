//
// Created by claiff on 17.05.22.
//
#include <SFML/Graphics/RenderTarget.hpp>

#include "animate_rectangle_shape.hpp"
#include "utils/timer_policy.hpp"

namespace entity
{
	AnimateRectangleShape::AnimateRectangleShape( sf::RectangleShape const& view,
												  AnimateRectangleShape::RegistratorType const& registrator,
												  unsigned int reload_ms )
			: mView( view )
			, mRegistrator( registrator )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( reload_ms ))
			, mIsEnableAnimation( false )
	{
		FixSprite();
	}

	void AnimateRectangleShape::draw( sf::RenderTarget& target, const sf::RenderStates& states ) const
	{
		if( mIsEnableAnimation && mTimerPolicy->IsTime())
		{
			ApplyNewView();
		}
		target.draw( mView );
	}

	void AnimateRectangleShape::ApplyNewView() const
	{
		auto sprite = mRegistrator->Get();
		mView.setTexture( sprite.getTexture());
		mView.setTextureRect( sprite.getTextureRect());
	}

	void AnimateRectangleShape::FixSprite()
	{
		mView.setOrigin( mView.getSize() / 2.f );
	}

	void AnimateRectangleShape::Move( const sf::Vector2f& step )
	{
		mView.move( step );
	}

	void AnimateRectangleShape::SetRotation( const sf::Angle& angle )
	{
		mView.setRotation( angle );
	}

	sf::Angle AnimateRectangleShape::GetRotation() const
	{
		return mView.getRotation();
	}

	sf::FloatRect AnimateRectangleShape::GetPlayerRect() const
	{
		sf::Vector2f origin = {mView.getOrigin().x * mView.getScale().x, mView.getOrigin().y * mView.getScale().y};
		sf::Vector2f position{mView.getPosition().x, mView.getPosition().y};
		sf::Vector2f size = mView.getSize();
		return {position - origin, size};
	}

	void AnimateRectangleShape::SetAnimateEnable() noexcept
	{
		mIsEnableAnimation = true;
	}

	void AnimateRectangleShape::SetAnimateDisable() noexcept
	{
		mIsEnableAnimation = false;
	}


} // entity