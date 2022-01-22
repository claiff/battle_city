//
// Created by claif on 08.01.2022.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <mingw.thread.h>
#include <atomic>
#include <mingw.mutex.h>

#include "types/iwindow.hpp"
#include "layers/types/ilayer.hpp"

namespace main_program
{
	class Window
			: public types::IWindow
	{
	public:
		Window( layer::types::ILayerPtr const& layers );
		~Window() override;
		void ReDraw() const override;
	private:
		void DrawSprite() const;

		mutable sf::RenderWindow *mWindow;
		layer::types::ILayerPtr const& mLayers;
		mutable std::mutex mDrawSpriteMutex;

	};

}
