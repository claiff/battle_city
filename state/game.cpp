//
// Created by claiff on 26.04.22.
//

#include "game.hpp"
#include "menu.hpp"
#include "app/types/ikeys.hpp"

namespace state
{
	std::shared_ptr < Game > Game::mInstance = nullptr;

	Game::Game( std::shared_ptr < sf::RenderWindow > const& window )
			: IState( window )
	{

	}

	void Game::Update()
	{

	}

	void Game::Draw()
	{
		mWindow->clear( {0x00, 0x00, 0x00} );
		mWindow->display();
	}

	void Game::HandleKeys( app::types::Keys key, app::Game* game )
	{
		using namespace app::types;

		if( key == Keys::RealizeUp )
		{
			game->ChangeState( Menu::GetInstance( mWindow ));
		}
	}

	std::shared_ptr < Game > Game::GetInstance( std::shared_ptr < sf::RenderWindow > const& window )
	{
		if( !mInstance )
		{
			mInstance = std::make_shared < Game >( window );
		}
		return mInstance;
	}


}