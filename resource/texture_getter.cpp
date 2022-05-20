//
// Created by claiff on 19.05.22.
//

#include "texture_getter.hpp"

namespace resource
{
	std::shared_ptr < sf::Texture >  TextureGetter::mTexture = nullptr;

	sf::Texture& TextureGetter::Get()
	{
		if( !mTexture )
		{
			CreateTexture();
		}
		return *mTexture;
	}

	void TextureGetter::CreateTexture()
	{
		static const std::string TEXTURE_PATH = "../../battle_city/media/general_sprites.png";

		mTexture = std::make_shared < sf::Texture >();
		auto is_load_file = mTexture->loadFromFile( TEXTURE_PATH );
		assert( is_load_file );
	}
}