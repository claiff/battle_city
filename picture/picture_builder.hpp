//
// Created by claif on 16.01.2022.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <mingw.mutex.h>

#include "types/ipicture_builder.hpp"

namespace picture
{
	class PictureBuilder
			: public types::IPictureBuilder
	{
	public:
		explicit PictureBuilder( sf::Sprite& draw_sprite );
		~PictureBuilder() override = default;

		void ReDraw() override;
	private:
		sf::Sprite& mDrawSprite;
		std::mutex mSpriteMutex;
	};
}

