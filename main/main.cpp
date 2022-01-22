//
// Created by claif on 08.01.2022.
//

#include <mingw.thread.h>

#include "game.hpp"
#include "window.hpp"
#include "picture/picture_builder.hpp"
#include "resource/png/manager.hpp"
#include "layers/layers_builder.hpp"

int main()
{
	layer::LayersBuilder builder{};
	auto layers = builder.MakeLayersDecorators();
	auto controllers = builder.MakeControllersClass();

	auto window = std::make_shared < main_program::Window >(  layers );
	auto picture_builder = std::make_shared < picture::PictureBuilder >( controllers );
	main_program::Game game{window, picture_builder};
	game.Play();
	return 0;
}
