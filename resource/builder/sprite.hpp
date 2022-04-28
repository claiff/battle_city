//
// Created by claiff on 27.04.22.
//


#pragma once

#include "resource/manager.hpp"

namespace resource::builder
{
	class Sprite
	{
	public:
		Sprite() = default;
		~Sprite() = default;

		Manager Build();
		[[nodiscard]] sf::Texture GetTexture() const;
	};
}

