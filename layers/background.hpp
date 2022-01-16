//
// Created by claif on 16.01.2022.
//

#pragma once

#include "types/ilayer.hpp"

namespace layer
{
	class Background : public types::ILayer
	{
	public:
		Background() = default;
		~Background() = default;

		sf::Sprite GetSprite() override;
	};
}

