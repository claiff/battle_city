//
// Created by claiff on 08.05.22.
//

#include <SFML/include/SFML/Graphics/RenderTarget.hpp>

#include "player.hpp"

namespace entity
{
	//
	//Constructors
	//

	Player::Player( resource::RectSprite const& view, layer::types::LayerPtr const& layers,
					MovementInfo const& move_info )
			: mView( view )
			, mLayers( layers )
			, mTimerPolicy( std::make_shared < utils::TimerPolicy >( move_info.period_ms ))
			, mStepMove( move_info.step )
			, mDirection( types::Direction::Up )
			, mIsMove( false )
	{
		FixSprite();
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
	}

	void Player::StopMove( types::Direction direction )
	{
		if( direction != mDirection )
		{
			return;
		}
		mIsMove = false;
	}

	sf::Vector2f Player::GetPosition() const
	{
		return mView.getPosition();
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

	void Player::FixSprite()
	{
		sf::Vector2f center_point = {static_cast<float>(mView.getTextureRect().width / 2),
									 static_cast<float>(mView.getTextureRect().height / 2)};
		mView.setOrigin( center_point );
		mView.move( {static_cast<float>(center_point.x * mView.getScale().x),
					 static_cast<float>(center_point.y * mView.getScale().y)} );
	}

	void Player::ApplyRotation()
	{
		auto angle_on_direction = ConvertDirectionToAngle( mDirection );
		if( angle_on_direction != mView.getRotation())
		{
			mView.setRotation( angle_on_direction );
		}
	}

	void Player::ApplyMovement()
	{
		auto step = GetStepOnDirection();
		if( IsEnableStep( step ))
		{
			mView.move( step );
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
		auto rect = GetPlayerRect( step );
		auto collisions = mLayers->GetCollisions( rect );
		return collisions.empty();
	}

	sf::FloatRect Player::GetPlayerRect( sf::Vector2f const& step ) const noexcept
	{
		sf::Vector2f origin = {mView.getOrigin().x * mView.getScale().x, mView.getOrigin().y * mView.getScale().y};
		sf::Vector2f position{mView.getPosition().x + step.x, mView.getPosition().y + step.y};
		sf::Vector2f size = mView.GetSize();
		return {position - origin, size};
	}


}