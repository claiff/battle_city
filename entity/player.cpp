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

	Player::Player( TankInfoRegistrator& tanks_set, builder::Projectile const& projectile_builder,
					layer::types::LayerPtr const& layers )
			:
			mTanksSet( tanks_set )
			, mProjectileBuilder( projectile_builder )
			, mLayers( layers )
			, mDirection( types::Direction::Up )
			, mIsMove( false )
	{
		mCurrentTank = mTanksSet.Get();
		mMovementPolicy = std::make_shared < utils::TimerPolicy >( mCurrentTank.speed.period_ms );
	}

	//
	//Public methods
	//

	void Player::Fire()
	{
		static int counter = 0;
		if( mProjectiles.size() >= mCurrentTank.count_projectiles )
		{
			return;
		}
		mProjectiles.push_back( GetProjectile());

		if(counter > 4)
		{
			mTanksSet.ResetCount();
			Upgrade();
			counter = 0;
		}
		else
		{
			Upgrade();
			counter++;
		}
	}

	void Player::StartMove( types::Direction direction )
	{
		mDirection = direction;
		//TODO Сделать через политику таймера
		// вариант к политике притянуть декоратор отключения/включения
		mIsMove = true;
		mCurrentTank.mView->SetAnimation( mIsMove );
	}

	void Player::StopMove( types::Direction direction )
	{
		if( direction != mDirection )
		{
			return;
		}
		mIsMove = false;
		mCurrentTank.mView->SetAnimation( mIsMove );
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
		target.draw( *mCurrentTank.mView );
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
		if( angle_on_direction != mCurrentTank.mView->GetRotation())
		{
			mCurrentTank.mView->SetRotation( angle_on_direction );
		}
	}

	void Player::ApplyPlayerMovement()
	{
		auto step = utils::DirectionHelper::StepOnDirection( mDirection, mStepMove );
		if( IsEnableStep( step ))
		{
			mCurrentTank.mView->Move( step );
		}
	}

	bool Player::IsEnableStep( sf::Vector2f const& step ) const noexcept
	{
		auto rect = mCurrentTank.mView->GetPlayerRect();
		rect.left += step.x;
		rect.top += step.y;
		auto collisions = mLayers->GetCollisions( rect );
		return collisions.empty();
	}

	Projectile Player::GetProjectile() const
	{
		auto position = GetProjectilePosition();
		auto direction = utils::DirectionHelper::AngleToDirection( mCurrentTank.mView->GetRotation());
		return mProjectileBuilder.Build( position, direction );
	}

	sf::Vector2f Player::GetProjectilePosition() const
	{
		auto view_rect = mCurrentTank.mView->GetPlayerRect();
		auto direction = utils::DirectionHelper::AngleToDirection( mCurrentTank.mView->GetRotation());
		auto position = view_rect.getPosition();
		CorrectPosition( view_rect, direction, position );
		return position;
	}

	void
	Player::CorrectPosition( sf::FloatRect const& view_rect, types::Direction direction, sf::Vector2f& position ) const
	{
		switch( direction )
		{
			case types::Direction::Up:
				position.x += view_rect.width / 2;
				break;
			case types::Direction::Right:
				position.x += view_rect.width;
				position.y += view_rect.height / 2;
				break;
			case types::Direction::Down:
				position.x += view_rect.width / 2;
				position.y += view_rect.height;
				break;
			case types::Direction::Left:
				position.y += view_rect.height / 2;
				break;
			default:
				break;
		}
	}

	void Player::Upgrade()
	{
		mCurrentTank = mTanksSet.Get();
	}
}