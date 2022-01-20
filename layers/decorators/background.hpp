//
// Created by claif on 16.01.2022.
//

#pragma once

#include "SFML/include/SFML/Graphics/RenderTexture.hpp"

#include "layers/types/ilayer.hpp"
#include "layers/controller/background.hpp"

namespace layer
{
	class Background
			: public types::ILayer
	{
	public:
		explicit Background( controller::Background const& controller );
		~Background() override = default;

		sf::Sprite GetSprite() override;
	private:
		void FillOnBackground( sf::Sprite& sprite );
		void ShiftSpriteX( sf::Sprite& sprite );
		void ShiftSpriteY( sf::Sprite& sprite );
		void ResetSpriteX(sf::Sprite& sprite);

		controller::Background mController;
	};
}

