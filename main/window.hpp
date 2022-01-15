//
// Created by claif on 08.01.2022.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "types/iwindow.hpp"
#include <mingw.thread.h>
#include <atomic>
namespace main_program
{
	class Window
			: public types::IWindow
	{
	public:
		Window( sf::Rect < unsigned int > const& rect, sf::String const& title, sf::Sprite const& drawing_sprite );
		~Window() override;
		void ReDraw() const override;
	private:
		mutable sf::RenderWindow *mWindow;
		sf::Sprite const& mDrawingSprite;
	};

}
