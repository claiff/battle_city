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
		ApplyLayers( sprite_manager );
		ApplyPlayer( sprite_manager );
	}

	void Game::ApplyLayers( resource::Manager const& manager )
	{

		auto layers = std::make_shared < layer::Border >( manager );
		layers->Apply( std::make_shared < layer::Background >( manager ));
		mLayers = layers;
	}

	void Game::ApplyPlayer( resource::Manager const& manager )
	{
		auto sprite = manager.Get( resource::Id::Player );
		mPlayer = std::make_shared < entity::Player >( sprite );
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
		if( mPlayer )
		{
			mWindow->draw( *mPlayer );
		}

		mWindow->display();
	}

	void Game::HandleKeys( app::types::Keys key, app::Game* game )
	{
		using namespace app::types;

		if( key == Keys::PushUp )
		{
			auto position = mPlayer->GetPosition();
			position.y -= 50;
			auto collisions = mLayers->GetCollisions( position );
			if( collisions.empty())
			{
				mPlayer->Move( {0, -50} );
			}
		}
		if( key == Keys::PushDown )
		{
			mPlayer->Move( {0, 50} );
		}
		if( key == Keys::PushLeft )
		{
			mPlayer->Move( {-50, 0} );
		}
		if( key == Keys::PushRight )
		{
			mPlayer->Move( {50, 0} );
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