//
// Created by claiff on 08.05.22.
//

#include <SFML/include/SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "player.hpp"
#include "utils/direction_helper.hpp"

namespace entity
{
	//
	//Constructors
	//

	Player::Player( AnimateRectangleShape const& view, builder::Projectile const& projectile_builder,
					layer::types::LayerPtr const& layers,
					types::MovementInfo const& move_info )
			:
			mView( view )
			, mProjectileBuilder( projectile_builder )
			, mLayers( layers )
			, mMovementPolicy( std::make_shared < utils::TimerPolicy >( move_info.period_ms ))
			, mStepMove( move_info.step )
			, mDirection( types::Direction::Up )
			, mIsMove( false )
	{
		ApplyRotation();
	}

	//
	//Public methods
	//

	void Player::Fire()
	{
		auto position = mView.GetPlayerRect().getPosition();
		auto direction = utils::DirectionHelper::AngleToDirection( mView.GetRotation());
		auto projectile = mProjectileBuilder.Build( position, direction );
		mProjectiles.push_back( projectile );
	}

	void Player::StartMove( types::Direction direction )
	{
		mDirection = direction;
		//TODO Сделать через политику таймера
		// вариант к политике притянуть декоратор отключения/включения
		mIsMove = true;
		mView.SetAnimation( mIsMove );
	}

	void Player::StopMove( types::Direction direction )
	{
		if( direction != mDirection )
		{
			return;
		}
		mIsMove = false;
		mView.SetAnimation( mIsMove );
	}

	void Player::Update()
	{
		ApplyProjectiles();
		if( !mIsMove || !mMovementPolicy->IsTime())
		{
			return;
		}

		ApplyRotation();
		ApplyPlayerMovement();
	}

	void Player::ApplyProjectiles()
	{
		for( auto it = mProjectiles.begin(); it != mProjectiles.end(); ++it )
		{
			auto rect = it->GetRect();
			auto collisions = mLayers->GetCollisions( rect );
			if( collisions.empty())
			{
				it->Update();
			}
			else
			{
				it = mProjectiles.erase( it );
			}
		}
	}

	void Player::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		target.draw( mView );
		for( const auto& projectile: mProjectiles )
		{
			target.draw( projectile );
		}
	}

	//
	//Private methods
	//

	void Player::ApplyRotation()
	{
		auto angle_on_direction = utils::DirectionHelper::DirectionToAngle( mDirection );
		if( angle_on_direction != mView.GetRotation())
		{
			mView.SetRotation( angle_on_direction );
		}
	}

	void Player::ApplyPlayerMovement()
	{
		auto step = utils::DirectionHelper::StepOnDirection( mDirection, mStepMove );
		if( IsEnableStep( step ))
		{
			mView.Move( step );
		}
	}

	bool Player::IsEnableStep( sf::Vector2f const& step ) const noexcept
	{
		auto rect = mView.GetPlayerRect();
		rect.left += step.x;
		rect.top += step.y;
		auto collisions = mLayers->GetCollisions( rect );
		return collisions.empty();
	}
}