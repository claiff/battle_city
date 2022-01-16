//
// Created by claif on 08.01.2022.
//

#include "game.hpp"
#include "window.hpp"
#include <mingw.thread.h>

namespace main_program
{

	Game::Game( types::IWindowPtr const& window, picture::types::IPictureBuilderPtr const& picture_builder )
			: mWindow( window )
			, mPictureBuilder( picture_builder )
	{

	}

	void Game::Play()
	{
		std::thread picture_builder_thread{&picture::types::IPictureBuilder::ReDraw, mPictureBuilder};
		picture_builder_thread.detach();

		mWindow->ReDraw();
	}
}