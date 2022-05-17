//
// Created by claiff on 08.05.22.
//


#pragma once

#include "types/ientity.hpp"
#include "utils/timer_policy.hpp"
#include "layer/types/ilayer.hpp"
#include "animate_rectangle_shape.hpp"

namespace entity
{
	struct MovementInfo
	{
		float step;
		unsigned int period_ms;
	};

	class Player
			: public types::IEntity
	{
	public:
		Player( AnimateRectangleShape const& view, layer::types::LayerPtr const& layers,
				MovementInfo const& move_info );
		~Player() override = default;

		void Fire() override;
		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
		void Update() override;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		void ApplyRotation();
		void ApplyMovement();
		sf::Vector2f GetStepOnDirection() const noexcept;
		bool IsEnableStep( sf::Vector2f const& step ) const noexcept;
		sf::Angle ConvertDirectionToAngle( types::Direction direction ) const noexcept;

		utils::types::IPolicyPtr mTimerPolicy;
		float mStepMove;
		types::Direction mDirection;
		bool mIsMove;
		layer::types::LayerPtr mLayers;
		AnimateRectangleShape mView;
	};
}

