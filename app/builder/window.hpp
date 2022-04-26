//
// Created by claiff on 26.04.22.
//


#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

namespace app::builder
{
	class Window
	{
	public:
		Window() = default;
		~Window() = default;

		std::shared_ptr<sf::RenderWindow> Build();
	};
}

