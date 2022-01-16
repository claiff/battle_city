//
// Created by claif on 08.01.2022.
//

#pragma once
#include <mingw.thread.h>

#include "types/iwindow.hpp"
#include "types/igame.hpp"
#include "picture/types/ipicture_builder.hpp"

namespace main_program
{
	class Game
			: public types::IGame
	{
	public:
		explicit Game( types::IWindowPtr const& window, picture::types::IPictureBuilderPtr const& picture_builder );
		~Game() override = default;

		void Play() override;
	private:
		types::IWindowPtr mWindow;
		picture::types::IPictureBuilderPtr mPictureBuilder;
		std::thread mDrawThread;
	};
}

