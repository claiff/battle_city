//
// Created by claiff on 27.04.22.
//

#include "manager.hpp"

namespace resource
{

	Manager::Manager( sf::Texture const& texture)
			: mTexture( texture )
	{

	}

	void Manager::Add( Id id, const sf::Rect < int >& rect_texture )
	{
		sf::Sprite sprite;
		sprite.setTexture( mTexture );
		sprite.setTextureRect( rect_texture );

		auto result = mResource.insert( std::make_pair( id, std::move( sprite )));
		assert( result.second );
	}

	sf::Sprite& Manager::Get( Id id )
	{
		auto find = mResource.find( id );
		assert( find != mResource.end());

		return find->second;
	}
}