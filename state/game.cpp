//
// Created by claiff on 26.04.22.
//

#include "game.hpp"
#include "menu.hpp"
#include "app/types/ikeys.hpp"
#include "layer/background.hpp"
#include "layer/border.hpp"
#include "resource/builder/sprite.hpp"

namespace state
{
	std::shared_ptr < Game > Game::mInstance = nullptr;

	Game::Game( std::shared_ptr < sf::RenderWindow > const& window )
			: IState( window )
	{
		auto sprite_manager = resource::builder::Sprite{}.Build();
		//mLayers = std::make_shared < layer::Background >( std::move( sprite_manager ));
		//mLayers = std::make_shared < layer::Border >( std::move( sprite_manager ));
		//mLayers.
		auto layers = std::make_shared < layer::Border >( sprite_manager );
		layers->Apply( std::make_shared < layer::Background >( sprite_manager ));
		mLayers = layers;
	}

	void Game::Update()
	{

	}

	void Game::Draw()
	{
		mWindow->clear( {0xFF, 0xFF, 0xFF} );
		if( mLayers )
		{
			mWindow->draw( *mLayers );
		}

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

	std::shared_ptr < Game >
	Game::GetInstance( std::shared_ptr < sf::RenderWindow > const& window )
	{
		if( !mInstance )
		{
			mInstance = std::make_shared < Game >( window );
		}
		return mInstance;
	}


}