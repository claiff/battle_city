//
// Created by claiff on 23.05.22.
//


#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "types/ilayer.hpp"
#include "utils/types/idecorator.hpp"
#include "resource/manager.hpp"
#include "resource/reader/landscape.hpp"

namespace layer
{
	class Landscape
			: public utils::types::IDecorator < types::ILayer >
	{
	public:
		Landscape( sf::FloatRect const& game_field, resource::Manager < resource::Id::Landscape > const& sprite_manager,
				   resource::reader::Landscape const& reader );
		~Landscape() override = default;

		types::CollisionsSet GetCollisions( const sf::FloatRect& rect ) override;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		[[nodiscard]] sf::Sprite GetSprite( resource::Id::Landscape landscape, sf::Vector2f const& shift ) const;
		void ApplyShift( sf::Vector2f& shift, sf::Sprite const& sprite ) const;
		sf::Vector2f GetSpriteSize( sf::Sprite const& sprite ) const;
		[[nodiscard]] bool IsOutXBorder( const sf::Vector2f& shift, const sf::Vector2f& sprite_size ) const noexcept;
		void ApplyNextLine( sf::Vector2f& shift, const sf::Vector2f& sprite_size ) const;

		unsigned int mLevel;
		sf::FloatRect mGameField;
		std::list < resource::Id::Landscape > mLandscapes;
		resource::Manager < resource::Id::Landscape > mSpriteManager;


	};
}
