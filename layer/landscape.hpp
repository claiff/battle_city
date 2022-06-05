//
// Created by claiff on 23.05.22.
//


#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "types/ilayer.hpp"
#include "utils/types/idecorator.hpp"
#include "resource/builder/landscape.hpp"

namespace layer
{
	class Landscape
			: public utils::types::IDecorator < types::ILayer >
	{
	public:
		Landscape( sf::FloatRect const& game_field, resource::builder::Landscape const& landscape_builder,
				   resource::reader::Landscape const& reader );
		~Landscape() override = default;

		types::CollisionsSet GetCollisions( const sf::FloatRect& rect ) override;
	protected:
		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override;
	private:
		unsigned int mLevel;
		sf::FloatRect mGameField;
		std::list < std::array < resource::types::ILandscapePtr , 4 > > mLandscapes;
		resource::builder::Landscape mLandscapeBuilder;
	};
}
