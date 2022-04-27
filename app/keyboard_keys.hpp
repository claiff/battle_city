//
// Created by claiff on 27.04.22.
//


#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "types/ikeys.hpp"

namespace app
{
	class KeyboardKeys
			: public types::IKeys
	{
	public:
		explicit KeyboardKeys( std::shared_ptr < sf::RenderWindow > const& window );
		~KeyboardKeys() override = default;

		types::Keys Get() override;
	private:
		void AddResult(types::Keys& result, types::Keys operand);
		[[nodiscard]] bool IsKeyPressed( sf::Event const& event ) const noexcept;

		std::shared_ptr < sf::RenderWindow > mWindow;
	};

}

