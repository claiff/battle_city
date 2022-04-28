//
// Created by claiff on 26.04.22.
//


#include "game.hpp"
#include "state/menu.hpp"

namespace app
{
	Game::Game( std::shared_ptr < sf::RenderWindow > const& window, types::KeysPtr const& keys )
			: mWindow( window )
			, mKeys( keys )
	{
		mState = state::Menu::GetInstance( window );
	}

	void Game::Run()
	{
		while( mWindow->isOpen())
		{
			auto keys = mKeys->Get();

			mState->HandleKeys( keys, this );
			mState->Draw();
		}
	}

	void Game::ChangeState( state::types::StatePtr const& new_state )
	{
		mState = new_state;
	}
}