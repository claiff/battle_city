//
// Created by claif on 19.01.2022.
//

#include "border_decorator.hpp"
#include "resource/png/manager.hpp"

namespace layer
{
	Border::Border( types::ILayerPtr const& layer, controller::Border const& controller )
			: IDecorator( layer )
			, mController( controller )
	{

	}

	sf::Sprite Border::GetSprite()
	{
		auto decorator_sprite = types::IDecorator::GetSprite();
		auto border_sprite = resource::png::Manager::GetBorderdSprite();
		mRenderTexture.clear();
		mRenderTexture.draw( decorator_sprite );
		FillBorder( border_sprite );
		mRenderTexture.display();

		mTexture = mRenderTexture.getTexture();
		return sf::Sprite{mTexture};
	}

	void Border::FillBorder( sf::Sprite& sprite )
	{
		DrawVerticalBorders( sprite );
		DrawHorizontalBorders( sprite );
	}

	void Border::DrawVerticalBorders( sf::Sprite& sprite )
	{
		SetPosition( 0, 0, sprite );
		for( auto y = 0; y < 32; y++ )
		{
			for( auto x = 0; x < 2; x++ )
			{
				ShiftSpriteX( sprite );
				mRenderTexture.draw( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite );
		}

		SetPosition( 28, 0, sprite );

		for( auto y = 0; y < 32; y++ )
		{
			for( auto x = 0; x < 4; x++ )
			{
				ShiftSpriteX( sprite );
				mRenderTexture.draw( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite, 28 );
		}
	}


	void Border::DrawHorizontalBorders( sf::Sprite& sprite )
	{
		SetPosition( 0, 0, sprite );
		for( auto y = 0; y < 1; y++ )
		{
			for( auto x = 0; x < 32; x++ )
			{
				ShiftSpriteX( sprite );
				mRenderTexture.draw( sprite );
			}
		}

		SetPosition( 0, 31, sprite );

		for( auto y = 0; y < 1; y++ )
		{
			for( auto x = 0; x < 32; x++ )
			{
				ShiftSpriteX( sprite );
				mRenderTexture.draw( sprite );
			}
		}
	}

	void Border::ShiftSpriteX( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		sprite.setPosition( position.x + width, position.y );
	}

	void Border::ShiftSpriteY( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto height = sprite.getTextureRect().height * sprite.getScale().y;
		sprite.setPosition( position.x, position.y + height );
	}

	void Border::ResetSpriteX( sf::Sprite& sprite, float default_value )
	{
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		auto position = sprite.getPosition();
		sprite.setPosition( default_value * width, position.y );
	}

	void Border::SetPosition( float x, float y, sf::Sprite& sprite )
	{
		auto height = sprite.getTextureRect().height * sprite.getScale().y;
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		sprite.setPosition( x * width, y * height );
	}

}