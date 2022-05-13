//
// Created by claiff on 08.05.22.
//


#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "types/ientity.hpp"
#include "utils/timer_policy.hpp"
#include "layer/types/ilayer.hpp"
#include "resource/rect_sprite.hpp"

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
		Player( sf::RectangleShape const& view, layer::types::LayerPtr const& layers, MovementInfo const& move_info );
		~Player() override = default;

		void Fire() override;
		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
		sf::Vector2f GetPosition() const override;
		void Update() override;

	protected:
		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		void FixSprite();
		void ApplyRotation();
		void ApplyMovement();
		sf::Vector2f GetStepOnDirection() const noexcept;
		bool IsEnableStep( sf::Vector2f const& step ) const noexcept;
		sf::FloatRect GetPlayerRect( sf::Vector2f const& step ) const noexcept;
		sf::Angle ConvertDirectionToAngle( types::Direction direction ) const noexcept;

		sf::RectangleShape mView;
		utils::types::IPolicyPtr mTimerPolicy;
		float mStepMove;
		types::Direction mDirection;
		bool mIsMove;
		layer::types::LayerPtr mLayers;
	};
}

