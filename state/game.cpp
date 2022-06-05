//
// Created by claiff on 26.04.22.
//

#include "game.hpp"
#include "menu.hpp"

#include "app/types/ikeys.hpp"

#include "layer/border.hpp"
#include "layer/landscape.hpp"

#include "entity/builder/player.hpp"

#include "resource/reader/landscape.hpp"
#include "resource/parser/landscape.hpp"
#include "resource/builder/landscape.hpp"
#include "resource/builder/ally_tank.hpp"
#include "resource/builder/border.hpp"
#include "resource/texture_getter.hpp"
#include "resource/landscape/builder/manager.hpp"

namespace state
{
	std::shared_ptr < Game > Game::mInstance = nullptr;

	//
	//Constructors
	//

	Game::Game( std::shared_ptr < sf::RenderWindow > const& window )
			: IState( window )
	{
		ApplyLayers();
		mPlayer = entity::builder::Player{}.Build( resource::builder::AllyTank{}.Build(), mLayers );
	}

	void Game::ApplyLayers()
	{
		auto layers = std::make_shared < layer::Border >( resource::builder::Border{}.Build());
		auto game_rect = layers->GetGameRect();

		resource::parser::Landscape parser;
		resource::reader::Landscape reader{"layer/levels/", parser};

		auto manager = resource::landscape::builder::Manager{}.Build();
		layers->Apply(
				std::make_shared < layer::Landscape >( game_rect,
													   resource::builder::Landscape{reader, game_rect, manager,},
													   reader ));
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
		//DrawPlayer();

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
		else if( IsKeyFire( key ))
		{
			mPlayer->Fire();
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

	bool Game::IsKeyFire( const app::types::Keys& key ) const noexcept
	{
		using namespace app::types;
		return key == Keys::PushUse;
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