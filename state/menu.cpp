//
// Created by claiff on 26.04.22.
//

#include "menu.hpp"
#include "app/game.hpp"
#include "game.hpp"

namespace state
{
	std::shared_ptr < Menu > Menu::mInstance = nullptr;

	Menu::Menu( std::shared_ptr < sf::RenderWindow > const& window )
			: types::IState( window )
	{

	}

	void Menu::Update()
	{

	}

	void Menu::Draw()
	{
		mWindow->clear({0xFF,0xFF,0xFF});
	}

	void Menu::HandleKeys( types::Keys key, app::Game* game )
	{
		if( key == types::Keys::PushUp )
		{
			game->ChangeState( Game::GetInstance( mWindow ));
		}
	}

	std::shared_ptr < Menu > Menu::GetInstance( std::shared_ptr < sf::RenderWindow > const& window )
	{
		if( !mInstance )
		{
			mInstance = std::make_shared < Menu >( window );
		}
		return mInstance;
	}


}