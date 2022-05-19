//
// Created by claiff on 08.05.22.
//


#pragma once

#include <list>

#include "types/itank_entity.hpp"
#include "utils/timer_policy.hpp"
#include "layer/types/ilayer.hpp"
#include "animate_rectangle_shape.hpp"
#include "builder/projectile.hpp"
#include "utils/continue_registrator.hpp"

namespace entity
{
	struct TankInfo
	{
		std::shared_ptr<AnimateRectangleShape> mView;
		types::MovementInfo speed;
		uint8_t count_projectiles;
	};
	using TankInfoRegistrator = utils::ContinueRegistrator < TankInfo >;

	class Player
			: public types::ITankEntity
	{
	public:
		Player( TankInfoRegistrator& tanks_set, builder::Projectile const& projectile_builder,
				layer::types::LayerPtr const& layers );
		~Player() override = default;

		void Fire() override;
		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
		void Update() override;
		void Upgrade() override;
	protected:
		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		void ApplyProjectiles();
		void ApplyRotation();
		void ApplyPlayerMovement();
		bool IsEnableStep( sf::Vector2f const& step ) const noexcept;
		Projectile GetProjectile() const;
		sf::Vector2f GetProjectilePosition() const;
		void
		CorrectPosition( sf::FloatRect const& view_rect, types::Direction direction, sf::Vector2f& position ) const;

		utils::types::IPolicyPtr mMovementPolicy;
		float mStepMove;
		types::Direction mDirection;
		bool mIsMove;
		layer::types::LayerPtr mLayers;

		builder::Projectile mProjectileBuilder;
		std::list < Projectile > mProjectiles;
		TankInfo& mCurrentTank;
		TankInfoRegistrator mTanksSet;
	};
}

