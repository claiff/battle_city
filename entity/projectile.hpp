//
// Created by claiff on 17.05.22.
//


#pragma once

#include "types/ientity.hpp"
#include "utils/types/ipolicy.hpp"

namespace entity
{
	struct ProjectileInfo
			: types::MovementInfo
	{
		types::Direction direction;
	};

	class Projectile
			: public types::IEntity
	{
	public:
		Projectile( sf::RectangleShape const& view, ProjectileInfo const& move_info );
		~Projectile() override = default;

		void Update() override;
		sf::FloatRect GetRect() const;
	protected:
		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override;
	private:
		sf::Vector2f ConvertDirectionToFloat( types::Direction direction ) const;

		sf::RectangleShape mView;
		utils::types::IPolicyPtr mTimerPolicy;
		sf::Vector2f mStepMove;
	};
}

