//
// Created by claiff on 31.05.22.
//

#include "manager.hpp"
#include "resource/texture_getter.hpp"

namespace resource::landscape::builder
{
	resource::landscape::Manager Manager::Build() const
	{
		static const sf::Vector2i BACKGROUND_POSITION = {337, 0};
		static const sf::Vector2i BRICK_POSITION = {256, 0};
		static const sf::Vector2i IRON_POSITION = {256, 16};
		static const sf::Vector2i SIZE = {8, 8};

		resource::landscape::Manager result{resource::TextureGetter::Get()};
		result.Add( resource::landscape::Id::Landscape::None, {BACKGROUND_POSITION, SIZE} );
		result.Add( resource::landscape::Id::Landscape::Brick, {BRICK_POSITION, SIZE} );
		result.Add( resource::landscape::Id::Landscape::Iron, {IRON_POSITION, SIZE} );

		return result;
	}
}