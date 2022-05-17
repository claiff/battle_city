//
// Created by claiff on 14.05.22.
//


#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

#include "entity/types/ientity.hpp"
#include "utils/types/idecorator.hpp"
#include "utils/types/ipolicy.hpp"
#include "utils/types/registrator.hpp"

namespace entity::decorator
{
	class AnimateRectangleShape
			: public utils::types::IDecorator < types::IEntity >
	{
	public:
		AnimateRectangleShape( utils::types::RegistratorPtr<sf::Sprite> const& sprites_set, unsigned int reload_ms );
		~AnimateRectangleShape() override = default;

		void Fire() override;
		void Update() override;
		void StartMove( types::Direction direction ) override;
		void StopMove( types::Direction direction ) override;
	protected:
		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override;
	private:
		void ApplyNewView();

		utils::types::RegistratorPtr<sf::Sprite> mSpritesSet;
		utils::types::IPolicyPtr mTimerPolicy;
	};
}

