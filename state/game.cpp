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

	//
	//Constructors
	//

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
		sprite.setPosition( {200, 200} );
		mPlayer = std::make_shared < entity::Player >( sprite, mLayers, entity::MovementInfo{5, 50} );
	}

	void Game::Update()
	{
		mPlayer->Update();
	}

	void Game::Draw()
	{
		mWindow->clear( {0xFF, 0xFF, 0xFF} );

		DrawLayers();
		DrawPlayer();

		mWindow->display();
	}

	void Game::DrawLayers()
	{
		if( mLayers )
		{
			mWindow->draw( *mLayers );
		}
	}

	void Game::DrawPlayer()
	{
		if( mPlayer )
		{
			mWindow->draw( *mPlayer );
		}
	}

	void Game::HandleKeys( app::types::Keys key, app::Game* game )
	{
		using namespace app::types;

		if( key == Keys::PushUp )
		{
			mPlayer->StartMove( entity::types::Direction::Up );
		}
		if( key == Keys::PushDown )
		{
			mPlayer->StartMove( entity::types::Direction::Down );
		}
		if( key == Keys::PushLeft )
		{
			mPlayer->StartMove( entity::types::Direction::Left );
		}
		if( key == Keys::PushRight )
		{
			mPlayer->StartMove( entity::types::Direction::Right );
		}
		if( IsKeyRealized( key ))
		{
			mPlayer->StopMove();
		}

	}

	bool Game::IsKeyRealized( const app::types::Keys& key ) const noexcept
	{
		using namespace app::types;
		return key == Keys::RealizeUp || key == Keys::RealizeDown || key == Keys::RealizeRight ||
			   key == Keys::RealizeLeft;
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