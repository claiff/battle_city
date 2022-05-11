//
// Created by claiff on 08.05.22.
//

#include <SFML/include/SFML/Graphics/RenderTarget.hpp>

#include "player.hpp"

namespace entity
{

	Player::Player( sf::Sprite const& view, layer::types::LayerPtr const& layers, MovementInfo const& move_info )
			: mView( view )
			, mLayers( layers )
	{
		mTimerPolicy = std::make_shared < utils::TimerPolicy >( move_info.period_ms );
		mStepMove = move_info.step;
		mDirection = types::Direction::Up;
		mIsMove = false;
	}

	void Player::Fire()
	{

	}

	void Player::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		target.draw( mView );
	}

	sf::Vector2f Player::GetPosition() const
	{
		return mView.getPosition();
	}

	void Player::StartMove( types::Direction direction )
	{
		mDirection = direction;
		//TODO Сделать через политику таймера
		// вариант к политике притянуть декоратор отключения/включения
		mIsMove = true;
	}

	void Player::StopMove( types::Direction direction )
	{
		if( direction != mDirection )
		{
			return;
		}
		mIsMove = false;
	}

	void Player::Move( const sf::Vector2f& step )
	{
		auto position = mView.getPosition();
		position += step;
		mView.setPosition( position );
	}

	void Player::Update()
	{
		if( !mIsMove || !mTimerPolicy->IsTime())
		{
			return;
		}

		auto step = GetStepOnDirection();
		if( IsEnableStep( step ))
		{
			Move( step );
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
		auto rect = GetPlayerRect( step );
		auto collisions = mLayers->GetCollisions( rect );
		return collisions.empty();
	}

	sf::Rect < float > Player::GetPlayerRect( sf::Vector2f const& step ) const noexcept
	{
		sf::Vector2f position{mView.getPosition().x + step.x, mView.getPosition().y + step.y};
		sf::Vector2f size{static_cast<float>(mView.getTextureRect().width * mView.getScale().x ),
						  static_cast<float>(mView.getTextureRect().height * mView.getScale().y)};
		return {position, size};
	}
}