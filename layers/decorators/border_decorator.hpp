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
		void DrawHorizontalLine(float x, float y, int height, sf::Sprite& sprite);
		void DrawVerticalLine(float x, float y, int width, sf::Sprite& sprite);

		sf::Texture mTexture;
		controller::Border mController;
	};
}