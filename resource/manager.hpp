//
// Created by claif on 16.01.2022.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace resource
{
	class Manager
	{
	public:
		Manager() = delete;
		~Manager() = default;

		static sf::Sprite GetBackgroundSprite();
		static sf::Sprite GetBorderdSprite();

		static sf::Sprite GetBrickSprite();
		static sf::Sprite GetIronSprite();
		static sf::Sprite GetIceSprite();
		static sf::Sprite GetGreenSprite();
		static sf::Sprite GetRiverSpriteI();
		static sf::Sprite GetRiverSpriteII();
		static sf::Sprite GetRiverSpriteIII();
	private:

		static sf::Sprite GetStandardSprite( sf::Vector2i const& position );
		static void CheckTexture();
		static void InitTexture();
		static sf::Texture mTextureSet;
	};
}

