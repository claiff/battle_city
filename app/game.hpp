//
// Created by claiff on 26.04.22.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "state/types/istate.hpp"
#include "types/ikeys.hpp"

namespace app
{
	class Game
	{
	public:
		explicit Game( std::shared_ptr < sf::RenderWindow > const& window, types::KeysPtr const& keys );
		~Game() = default;

		void Run();
		void ChangeState( state::types::StatePtr const& new_state );
	private:
		std::shared_ptr < sf::RenderWindow > mWindow;
		types::KeysPtr mKeys;
		state::types::StatePtr mState;
	};

}
