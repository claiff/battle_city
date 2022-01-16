//
// Created by claif on 08.01.2022.
//

#include <mingw.thread.h>

#include "game.hpp"
#include "window.hpp"
#include "picture/picture_builder.hpp"
#include "resource/manager.hpp"

int main()
{
	//FIXME Builders
	//FIXME config file
	sf::Rect < unsigned int > window_rect = {50, 50, 800, 600};
	sf::String title = "Title";
	auto draw_sprite = resource::Manager::GetBrickSprite();
	draw_sprite.setPosition( 100, 100 );
	auto window = std::make_shared < main_program::Window >( window_rect, title, draw_sprite );
	auto picture_builder = std::make_shared < picture::PictureBuilder >( draw_sprite );
	main_program::Game game{window, picture_builder};
	game.Play();
	return 0;
}
