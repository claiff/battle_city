//
// Created by claiff on 26.04.22.
//

#include <SFML/System/String.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "window.hpp"
#include "resource/reader/ini.hpp"

namespace app::builder
{
	std::shared_ptr < sf::RenderWindow > Window::Build()
	{
		static const std::string WINDOW_TITLE = "Battle city";
		static constexpr uint32_t WINDOW_STYLE = sf::Style::Close;

		auto window_width = std::stoi( resource::reader::Ini::GetValue( "default_window_width" ));
		auto window_height = std::stoi( resource::reader::Ini::GetValue( "default_window_height" ));

		auto window = std::make_shared < sf::RenderWindow >(
				sf::VideoMode{static_cast<unsigned int>(window_width), static_cast<unsigned int>(window_height)},
				WINDOW_TITLE, WINDOW_STYLE );

		window->setFramerateLimit( 60 );
		return window;
	}
}