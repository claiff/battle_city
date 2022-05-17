//
// Created by claiff on 26.04.22.
//

#include <SFML/Graphics/RectangleShape.hpp>

#include "game.hpp"
#include "menu.hpp"
#include "app/types/ikeys.hpp"
#include "layer/background.hpp"
#include "layer/border.hpp"
#include "resource/builder/sprite.hpp"
#include "entity/player_builder.hpp"

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
		mPlayer = entity::PlayerBuilder{}.Build( sprite_manager, mLayers );
	}

	void Game::ApplyLayers( resource::Manager const& manager )
	{
		auto layers = std::make_shared < layer::Border >( manager );
		layers->Apply( std::make_shared < layer::Background >( manager ));
		mLayers = layers;
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
		entity::types::Direction direction;
		if( IsKeyPushed( key ))
		{
			direction = ConvertKeysToDirection( key );
			mPlayer->StartMove( direction );
		}
		else if( IsKeyRealized( key ))
		{
			direction = ConvertKeysToDirection( key );
			mPlayer->StopMove( direction );
		}
	}

	bool Game::IsKeyPushed( app::types::Keys key ) const noexcept
	{
		using namespace app::types;
		return key == Keys::PushUp || key == Keys::PushDown || key == Keys::PushLeft || key == Keys::PushRight;
	}

	entity::types::Direction Game::ConvertKeysToDirection( app::types::Keys key ) const noexcept
	{
		using namespace app::types;
		using namespace entity::types;

		switch( key )
		{
			case Keys::PushUp :
			case Keys::RealizeUp :
				return Direction::Up;
			case Keys::PushDown:
			case Keys::RealizeDown:
				return Direction::Down;
			case Keys::PushLeft:
			case Keys::RealizeLeft:
				return Direction::Left;
			case Keys::PushRight:
			case Keys::RealizeRight:
				return Direction::Right;
			default:
				return Direction::Up;
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