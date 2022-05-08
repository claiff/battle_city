//
// Created by claiff on 26.04.22.
//


#pragma once

#include <memory>

#include "types/istate.hpp"
#include "app/game.hpp"
#include "layer/types/ilayer.hpp"
#include "entity/player.hpp"
#include "resource/manager.hpp"

namespace state
{
	class Game
			: public types::IState
	{
	public:
		explicit Game( std::shared_ptr < sf::RenderWindow > const& window );
		~Game() override = default;

		void Update() override;
		void Draw() override;
		void HandleKeys( app::types::Keys key, app::Game* game ) override;

		static std::shared_ptr < Game >
		GetInstance( std::shared_ptr < sf::RenderWindow > const& window );
	private:
		void ApplyLayers( resource::Manager const& manager );
		void ApplyPlayer( resource::Manager const& manager );
		static std::shared_ptr < Game > mInstance;

		layer::types::LayerPtr mLayers;
		entity::types::IEntityPtr mPlayer;
	};
}

