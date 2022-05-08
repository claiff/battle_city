//
// Created by claiff on 08.05.22.
//


#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "types/ientity.hpp"

namespace entity
{
	class Player
			: public types::IEntity
	{
	public:
		explicit Player( sf::Sprite const& view );
		~Player() override = default;

		void Move( sf::Vector2f const& step ) override;
		void Fire() override;
		sf::Vector2f GetPosition() const override;
	protected:
		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		sf::Sprite mView;
	};
}

