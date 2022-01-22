//
// Created by claif on 20.01.2022.
//

#include "ilayer.hpp"

namespace layer::types
{
	ILayer::ILayer()
	{
		if( !mRenderTexture.create( 800, 600 ))
		{
			throw "IDecorator::IDecorator Невозможно отрисовать mRenderTexture";
		}
	}

	void ILayer::ShiftSpriteX( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		sprite.setPosition( position.x + width, position.y );
	}

	void ILayer::ShiftSpriteY( sf::Sprite& sprite )
	{
		auto position = sprite.getPosition();
		auto height = sprite.getTextureRect().height * sprite.getScale().y;
		sprite.setPosition( position.x, position.y + height );
	}

	void ILayer::ResetSpriteX( sf::Sprite& sprite, float default_value )
	{
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		auto position = sprite.getPosition();
		sprite.setPosition( default_value * width, position.y );
	}

	void ILayer::SetPosition( float x, float y, sf::Sprite& sprite )
	{
		auto height = sprite.getTextureRect().height * sprite.getScale().y;
		auto width = sprite.getTextureRect().width * sprite.getScale().x;
		sprite.setPosition( x * width, y * height );
	}
}
