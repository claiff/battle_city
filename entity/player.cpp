//
// Created by claiff on 08.05.22.
//

#include <SFML/include/SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "player.hpp"

namespace entity
{
	//
	//Constructors
	//

	Player::Player( AnimateRectangleShape const& view, layer::types::LayerPtr const& layers,
					MovementInfo const& move_info )
			:
			mView( view )
			, mLayers( layers )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( move_info.period_ms ))
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
		if( !mIsMove || !mTimerPolicy->IsTime())
		{
			return;
		}

		ApplyRotation();
		ApplyMovement();
	}

	void Player::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		target.draw( mView );
	}

	//
	//Private methods
	//

	void Player::ApplyRotation()
	{
		auto angle_on_direction = ConvertDirectionToAngle( mDirection );
		if( angle_on_direction != mView.GetRotation())
		{
			mView.SetRotation( angle_on_direction );
		}
	}

	void Player::ApplyMovement()
	{
		auto step = GetStepOnDirection();
		if( IsEnableStep( step ))
		{
			mView.Move( step );
		}
	}


	sf::Angle Player::ConvertDirectionToAngle( types::Direction direction ) const noexcept
	{
		switch( direction )
		{
			case types::Direction::Up :
				return sf::degrees( 0 );
			case types::Direction::Right :
				return sf::degrees( 90 );
			case types::Direction::Down :
				return sf::degrees( 180 );
			case types::Direction::Left :
				return sf::degrees( 270 );
			default:
				return sf::degrees( 0 );
		}
	}

	sf::Vector2f Player::GetStepOnDirection() const noexcept
	{
		static constexpr int ZERO_STEP = 0;

		sf::Vector2f result;
		switch( mDirection )
		{
			case types::Direction::Up:
				result = {ZERO_STEP, -mStepMove};
				break;
			case types::Direction::Down:
				result = {ZERO_STEP, mStepMove};
				break;
			case types::Direction::Left:
				result = {-mStepMove, ZERO_STEP};
				break;
			case types::Direction::Right:
				result = {mStepMove, ZERO_STEP};
				break;
			default:
				result = {};
		}
		return result;
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