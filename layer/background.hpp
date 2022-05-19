//
// Created by claiff on 27.04.22.
//


#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "types/ilayer.hpp"
#include "utils/types/idecorator.hpp"
#include "resource/manager.hpp"

namespace layer
{
	//TODO Deprecated после создания landscape слоя
	class Background
			: public utils::types::IDecorator < types::ILayer >
	{
	public:
		explicit Background( resource::Manager < resource::Id::Landscape > const& sprite_manager );
		~Background() override = default;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
		types::CollisionsSet GetCollisions( sf::Rect < float > const& rect ) override;
	private:
		void SetScaleOnFullWindow( sf::Sprite& sprite ) const;
		[[nodiscard]] sf::Vector2f GetScaleOnWhileWindow() const;

		resource::Manager< resource::Id::Landscape > mSpriteManager;
	};

}
