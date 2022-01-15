//
// Created by claif on 08.01.2022.
//
//#include "game.hpp"

#include "game.hpp"
#include "window.hpp"
#include <mingw.thread.h>

int main()
{
	using namespace std::chrono_literals;
	sf::Rect < unsigned int > window_rect = {50, 50, 800, 600};
	sf::String title = "Title";
	sf::Sprite drawing_sprite;
	drawing_sprite.setColor(sf::Color::Black);
	auto window = std::make_shared < main_program::Window >( window_rect, title, drawing_sprite );
	main_program::Game game{window};
	game.Play();
	return 0;
}
