//
// Created by claiff on 26.04.22.
//

#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

namespace app
{
	class Game
	{
	public:
		Game( std::shared_ptr<sf::RenderWindow> const& window );
		~Game() = default;

		void Run();
	private:
		std::shared_ptr<sf::RenderWindow> mWindow;
	};

}
