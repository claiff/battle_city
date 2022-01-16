//
// Created by claif on 08.01.2022.
//

#include <mingw.thread.h>

#include "game.hpp"
#include "window.hpp"
#include "picture/picture_builder.hpp"

int main()
{
	//FIXME Builders
	//FIXME config file
	sf::Rect < unsigned int > window_rect = {50, 50, 800, 600};
	sf::String title = "Title";
	sf::Sprite draw_sprite;
	draw_sprite.setTextureRect( sf::IntRect{50, 50, 800, 600} );
	draw_sprite.setColor( sf::Color::Blue );
	auto window = std::make_shared < main_program::Window >( window_rect, title, draw_sprite );
	auto picture_builder = std::make_shared < picture::PictureBuilder >( draw_sprite );
	main_program::Game game{window, picture_builder};
	game.Play();
	return 0;
}
