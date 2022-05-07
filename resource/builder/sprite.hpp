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

		[[nodiscard]] Manager Build() const;
	private:
		[[nodiscard]] sf::Vector2f GetScale() const;
		[[nodiscard]] sf::Vector2i GetSpriteSize() const;
		[[nodiscard]] sf::Vector2i GetWindowSize() const;

		sf::Rect < int > mWindow_rect;
	};
}

