//
// Created by claif on 19.01.2022.
//

#pragma once

#include "SFML/include/SFML/Graphics/RenderTexture.hpp"

#include "layers/types/idecorator.hpp"
#include "layers/controller/border.hpp"

namespace layer
{
	class Border
			: public types::IDecorator
	{
	public:
		explicit Border( types::ILayerPtr const& layer, controller::Border const& controller );
		~Border() override = default;

		sf::Sprite GetSprite() override;
	private:
		void FillBorder( sf::Sprite& sprite );
		void DrawVerticalBorders( sf::Sprite& sprite );
		void DrawHorizontalBorders( sf::Sprite& sprite );
		void ShiftSpriteX( sf::Sprite& sprite );
		void ShiftSpriteY( sf::Sprite& sprite );
		void ResetSpriteX( sf::Sprite& sprite, float default_value = 0);
		void SetPosition( float x, float y, sf::Sprite& sprite );

		sf::Texture mTexture;
		controller::Border mController;
	};
}