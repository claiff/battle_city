//
// Created by claiff on 27.04.22.
//

#include <SFML/Graphics/Texture.hpp>

#include "sprite.hpp"


namespace resource::builder
{
	//
	// Public methods
	//

	Manager Sprite::Build()
	{
		static const sf::Rect < int > BACKGROUND_RECT = {{336, 0},
														 {8,   8}};
		static const sf::Rect < int > BORDER_RECT = {{368, 0},
													 {8,   8}};
		sf::Texture texture = GetTexture();
		Manager result{texture};
		result.Add( resource::Id::Background, BACKGROUND_RECT );
		result.Add( resource::Id::Border, BORDER_RECT );
		return result;
	}

	//
	// Private methods
	//

	sf::Texture Sprite::GetTexture() const
	{
		sf::Texture result;
		auto path_texture = "../../battle_city/media/general_sprites.png";

		auto is_load_file = result.loadFromFile( path_texture );
		assert( is_load_file );
		return result;
	}
}