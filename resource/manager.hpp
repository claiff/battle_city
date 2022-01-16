//
// Created by claif on 16.01.2022.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace texture
{
	class Manager
	{
	public:
		Manager();
		~Manager() = default;

		static sf::Sprite GetBackGroundSprite();
	private:
		static sf::Texture mTextureSet;
	};
}

