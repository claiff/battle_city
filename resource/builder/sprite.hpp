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
		explicit Sprite( sf::Rect < int > const& window_rect );
		~Sprite() = default;

		[[nodiscard]] Manager Build() const;
		[[nodiscard]] sf::Texture GetTexture() const;

	private:
		sf::Rect < int > mWindow_rect;
	};
}

