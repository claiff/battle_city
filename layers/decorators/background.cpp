//
// Created by claif on 16.01.2022.
//

#include "background.hpp"
#include "resource/png/manager.hpp"

namespace layer
{
	Background::Background( controller::Background const& controller )
			: mController( controller )
	{

	}

	sf::Sprite Background::GetSprite()
	{
		auto sprite = resource::png::Manager::GetBackgroundSprite();

		mRenderTexture.clear( sf::Color::White );
		FillOnBackground( sprite );
		mRenderTexture.display();

		const sf::Texture& texture = mRenderTexture.getTexture();
		return sf::Sprite{texture};
	}

	void Background::FillOnBackground( sf::Sprite& sprite )
	{
		for( auto y = 0; y < 32; y++ )
		{
			for( auto x = 0; x < 32; x++ )
			{
				ShiftSpriteX( sprite );
				mRenderTexture.draw( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite );
		}
	}

	void Background::ShiftSpriteX( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		sprite.setPosition( position.x + width, position.y );
	}

	void Background::ShiftSpriteY( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto height = sprite.getTextureRect().height * sprite.getScale().y;
		sprite.setPosition( position.x, position.y + height );
	}

	void Background::ResetSpriteX( sf::Sprite& sprite )
	{
		static constexpr int ZERO_X = 0;
		auto position = sprite.getPosition();
		sprite.setPosition( ZERO_X, position.y );
	}


}