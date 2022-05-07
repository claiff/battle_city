//
// Created by claiff on 27.04.22.
//


#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "types/ilayer.hpp"
#include "resource/manager.hpp"

namespace layer
{
	class Background
			: public types::ILayer
	{
	public:
		explicit Background( const resource::Manager& sprite_manager );
		~Background() override = default;

		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override;
	private:
		resource::Manager mSpriteManager;
		sf::Vector2f GetScale() const;
	};

}
