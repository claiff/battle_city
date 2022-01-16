//
// Created by claif on 08.01.2022.
//

#include "game.hpp"
#include "window.hpp"
#include <mingw.thread.h>

namespace main_program
{

	Game::Game( types::IWindowPtr const& window )
			: mWindow( window )
	{

	}

	void Game::Play()
	{
		mWindow->ReDraw();
		//FIXME logic thread
	}
}