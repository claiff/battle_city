//
// Created by claif on 16.01.2022.
//

#include "background.hpp"
#include "resource/png/manager.hpp"

namespace layer
{
	Background::Background()
	{
		if( !mRenderTexture.create( 800, 600 ))
		{
			throw "IDecorator::IDecorator Невозможно отрисовать mRenderTexture";
		}
	}

	sf::Sprite Background::GetSprite()
	{
		auto sprite = resource::png::Manager::GetBackgroundSprite();

		mRenderTexture.clear( sf::Color::Red );
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
				mRenderTexture.draw( sprite );
				ShiftSpriteX( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite );
		}
	}
}