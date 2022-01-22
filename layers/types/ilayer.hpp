//
// Created by claif on 16.01.2022.
//

#pragma once

#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace layer::types
{
	class ILayer
	{
	public:
		ILayer();
		virtual ~ILayer() = default;

		virtual sf::Sprite GetSprite() = 0;
	protected:
		void ShiftSpriteX( sf::Sprite& sprite );
		void ShiftSpriteY( sf::Sprite& sprite );
		void ResetSpriteX( sf::Sprite& sprite, float default_value = 0);
		void SetPosition( float x, float y, sf::Sprite& sprite );

		sf::RenderTexture mRenderTexture;
	};

	using ILayerPtr = std::shared_ptr < ILayer >;
}