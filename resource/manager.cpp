//
// Created by claiff on 27.04.22.
//

#include "manager.hpp"

namespace resource
{
	Manager::Manager( std::string const& texture_path )
	{
		mTexture = std::make_shared <sf::Texture>();
		auto is_load_file = mTexture->loadFromFile( texture_path );
		assert( is_load_file );
	}

	void Manager::Add( Id id, const sf::Rect < int >& rect_texture, sf::Vector2f const& scale )
	{
		sf::Sprite sprite;
		sprite.setTexture( *mTexture );
		sprite.setTextureRect( rect_texture );
		sprite.setScale( scale );
		auto result = mResource.insert( std::make_pair( id, std::move( sprite )));
		assert( result.second );
	}

	sf::Sprite Manager::Get( Id id ) const
	{
		auto find = mResource.find( id );
		if( find == mResource.end())
		{
			find = mResource.find( id );
		}
		assert( find != mResource.end());
		auto result = find->second;
		return result;
	}


}