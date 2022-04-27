//
// Created by claiff on 26.04.22.
//


#pragma once

#include <memory>

#include "types/istate.hpp"


namespace state
{
	class Menu
			: public types::IState
	{
	public:
		explicit Menu( std::shared_ptr < sf::RenderWindow > const& window );
		~Menu() override = default;

		void Update() override;
		void Draw() override;
		void HandleKeys( app::types::Keys key, app::Game* game ) override;

		static std::shared_ptr < Menu > GetInstance( std::shared_ptr < sf::RenderWindow > const& window );
	private:
		static std::shared_ptr < Menu > mInstance;
	};
}


