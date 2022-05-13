//
// Created by claiff on 12.05.22.
//


#pragma once

#include <SFML/Graphics/Sprite.hpp>

namespace resource
{
	class RectSprite
			: public sf::Sprite
	{
	public:
		RectSprite() = default;
		~RectSprite() override = default;

		sf::Vector2f GetSize() const;
	};

}
