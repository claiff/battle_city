//
// Created by claiff on 23.05.22.
//

#include <SFML/Graphics/RenderTarget.hpp>

#include "landscape.hpp"

namespace layer
{
	Landscape::Landscape( sf::FloatRect const& game_field,
						  resource::builder::Landscape const& landscape_builder,
						  resource::reader::Landscape const& reader )
			: mLevel( 1 )
			, mLandscapeBuilder( landscape_builder )
			, mGameField( game_field )
	{
		mLandscapes = mLandscapeBuilder.Build(1);
	}

	types::CollisionsSet Landscape::GetCollisions( const sf::FloatRect& rect )
	{
		return layer::types::CollisionsSet();
	}

	void Landscape::draw( sf::RenderTarget& target, const sf::RenderStates& states ) const
	{
		if( mBase )
		{
			mBase->draw( target, states );
		}
		sf::Vector2f shift{};

		for( const auto& landscape: mLandscapes )
		{
			for(const auto& shape: landscape)
			{
				target.draw( *shape );
			}
		}
	}
}