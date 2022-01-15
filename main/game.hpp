//
// Created by claif on 08.01.2022.
//

#pragma once

#include "types/iwindow.hpp"
#include "types/igame.hpp"
#include <mingw.thread.h>

namespace main_program
{
	class Game
			: public types::IGame
	{
	public:
		explicit Game( types::IWindowPtr const& window );
		~Game() override = default;

		void Play() override;
	private:
		types::IWindowPtr mWindow;
		std::thread mDrawThread;
	};
}

