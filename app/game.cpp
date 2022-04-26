//
// Created by claiff on 26.04.22.
//


#include "game.hpp"
#include "state/menu.hpp"

namespace app
{
	Game::Game( std::shared_ptr < sf::RenderWindow > const& window )
			: mWindow( window )
	{
		mState = state::Menu::GetInstance( window );
	}

	void Game::Run()
	{
		while( mWindow->isOpen())
		{
			mState->Draw();
		}
	}

	void Game::ChangeState( state::types::StatePtr const& new_state )
	{
		mState = new_state;
	}
}