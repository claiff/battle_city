//
// Created by claiff on 08.05.22.
//


#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "types/ientity.hpp"
#include "utils/timer_policy.hpp"
#include "layer/types/ilayer.hpp"

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
		Player( sf::Sprite const& view, layer::types::LayerPtr const& layers, MovementInfo const& move_info );
		~Player() override = default;

		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
		void Move( const sf::Vector2f& step ) override;
		void Fire() override;
		sf::Vector2f GetPosition() const override;
		virtual void Update() override;

	protected:
		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		sf::Vector2f GetStepOnDirection() const noexcept;
		bool IsEnableStep( sf::Vector2f const& step ) const noexcept;
		sf::Sprite mView;
		utils::types::IPolicyPtr mTimerPolicy;
		float mStepMove;
		types::Direction mDirection;
		bool mIsMove;
		layer::types::LayerPtr mLayers;
	};
}

