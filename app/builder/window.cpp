//
// Created by claiff on 26.04.22.
//

#include <SFML/System/String.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "window.hpp"

namespace app::builder
{
	std::shared_ptr < sf::RenderWindow > Window::Build()
	{
		static constexpr unsigned int WINDOW_WIDTH = 1024;
		static constexpr unsigned int WINDOW_HEIGHT = 768;
		static const std::string WINDOW_TITLE = "Battle city";
		static constexpr uint32_t WINDOW_STYLE = sf::Style::Close;

		auto window = std::make_shared < sf::RenderWindow >( sf::VideoMode{sf::Vector2u{WINDOW_WIDTH, WINDOW_HEIGHT}},
																				   WINDOW_TITLE, WINDOW_STYLE );
		window->setFramerateLimit( 60 );
		return window;
	}
}