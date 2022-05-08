//
// Created by claiff on 27.04.22.
//


#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "types/ilayer.hpp"
#include "types/idecorator.hpp"
#include "resource/manager.hpp"

namespace layer
{
	class Background
			: public types::IDecorator < types::ILayer >
	{
	public:
		explicit Background( resource::Manager const& sprite_manager );
		~Background() override = default;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
		virtual types::CollisionsSet GetCollisions( const sf::Vector2f& position ) override;
	private:
		void SetScaleOnFullWindow( sf::Sprite& sprite ) const;
		[[nodiscard]] sf::Vector2f GetScaleOnWhileWindow() const;

		resource::Manager mSpriteManager;
	};

}
