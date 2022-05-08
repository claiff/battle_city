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
		/*!
		\brief Определяет масштабирование спрайта
		*/
		[[nodiscard]] sf::Vector2f GetScale( sf::Vector2i const& sprite_size ) const;

		/*!
		\brief Определяет размер спрайта по размеру окна
		*/
		[[nodiscard]] sf::Vector2f GetSpriteSizeOnWindow() const;

		/*!
		\brief Определяет размер окна по файлу settings
		*/
		[[nodiscard]] sf::Vector2i GetWindowSize() const;

		sf::Rect < int > mWindow_rect;
	};
}

