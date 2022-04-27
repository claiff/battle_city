//
// Created by claiff on 26.04.22.
//


#pragma once

#include <memory>

#include "types/istate.hpp"
#include "app/game.hpp"

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

		static std::shared_ptr < Game > GetInstance( std::shared_ptr < sf::RenderWindow > const& window );
	private:
		static std::shared_ptr < Game > mInstance;
	};
}

