//
// Created by claiff on 26.04.22.
//


#include "game.hpp"
#include "SFML/Graphics/Color.hpp"


namespace app
{
	Game::Game( std::shared_ptr < sf::RenderWindow > const& window )
			: mWindow( window )
	{

	}

	void Game::Run()
	{
		sf::Color color{0xDF, 0xEE, 0x11};
		while( mWindow->isOpen())
		{
			mWindow->clear( color );
			mWindow->display();
		}
	}
}