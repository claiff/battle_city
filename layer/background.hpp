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
		void SetScaleOnFullWindow( sf::Sprite& sprite ) const;
		[[nodiscard]] sf::Vector2f GetScaleOnWhileWindow() const;

		resource::Manager mSpriteManager;
	};

}
