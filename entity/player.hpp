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

namespace entity
{
	class Player
			: public types::ITankEntity
	{
	public:
		Player( AnimateRectangleShape const& view, builder::Projectile const& projectile_builder,
				layer::types::LayerPtr const& layers,
				types::MovementInfo const& move_info );
		~Player() override = default;

		void Fire() override;
		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
		void Update() override;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		void ApplyProjectiles();
		void ApplyRotation();
		void ApplyPlayerMovement();
		bool IsEnableStep( sf::Vector2f const& step ) const noexcept;


		utils::types::IPolicyPtr mMovementPolicy;
		float mStepMove;
		types::Direction mDirection;
		bool mIsMove;
		layer::types::LayerPtr mLayers;
		AnimateRectangleShape mView;
		builder::Projectile mProjectileBuilder;
		std::list < Projectile > mProjectiles;
	};
}

