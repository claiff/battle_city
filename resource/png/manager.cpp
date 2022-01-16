//
// Created by claif on 16.01.2022.
//

#include "manager.hpp"

namespace resource::png
{
	sf::Texture Manager::mTextureSet = {};

	sf::Sprite Manager::GetBackgroundSprite()
	{
		static const sf::Vector2i POSITION = {336, 0};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetBrickSprite()
	{
		static const sf::Vector2i POSITION = {320, 0};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetBorderdSprite()
	{
		static const sf::Vector2i POSITION = {368, 0};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetIronSprite()
	{
		static const sf::Vector2i POSITION = {256, 0};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetIceSprite()
	{
		static const sf::Vector2i POSITION = {288, 32};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetGreenSprite()
	{
		static const sf::Vector2i POSITION = {272, 32};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetRiverSpriteI()
	{
		static const sf::Vector2i POSITION = {256, 80};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}
	sf::Sprite Manager::GetRiverSpriteII()
	{
		static const sf::Vector2i POSITION = {264, 80};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetRiverSpriteIII()
	{
		static const sf::Vector2i POSITION = {272, 80};

		CheckTexture();
		return GetStandardSprite( POSITION );
	}

	sf::Sprite Manager::GetStandardSprite( sf::Vector2i const& position )
	{
		sf::Sprite result;
		result.setTexture( mTextureSet );
		result.setTextureRect( {position.x, position.y, 8, 8} );
		return result;
	}

	void Manager::CheckTexture()
	{
		if( mTextureSet.getSize() == sf::Vector2u{} )
		{
			InitTexture();
		}
	}

	void Manager::InitTexture()
	{
		//FIXME normal path
		static const std::string PATH = R"(C:\Users\claif\Documents\projects\battle_city\resource\png\general_sprites.png)";
		auto result = mTextureSet.loadFromFile( PATH );
	}
}