//
// Created by claiff on 26.04.22.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace app
{
	class Game;
}

namespace state::types
{
	enum class Keys
	{
		PushUp,
		RealizeUp,
		PushUse,
		RealizeUse,
	};

	class IState
	{
	public:
		explicit IState( std::shared_ptr < sf::RenderWindow > const& window )
				: mWindow( window )
		{
		}

		virtual ~IState() = default;

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void HandleKeys( Keys key, app::Game* game ) = 0;
	protected:
		std::shared_ptr < sf::RenderWindow > mWindow;
	};

	using StatePtr = std::shared_ptr < IState >;
}
