//
// Created by claiff on 26.04.22.
//

#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "state/types/istate.hpp"

namespace app
{
	class Game
	{
	public:
		Game( std::shared_ptr < sf::RenderWindow > const& window );
		~Game() = default;

		void Run();
		void ChangeState( state::types::StatePtr const& new_state );
	private:
		std::shared_ptr < sf::RenderWindow > mWindow;
		state::types::StatePtr mState;
	};

}
