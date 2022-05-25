//
// Created by claiff on 23.05.22.
//

#include <SFML/Graphics/RenderTarget.hpp>

#include "landscape.hpp"

namespace layer
{
	Landscape::Landscape( sf::FloatRect const& game_field,
						  const resource::Manager < resource::Id::Landscape >& sprite_manager,
						  levels::Reader const& reader )
			: mLevel( 1 )
			, mSpriteManager( sprite_manager )
			, mGameField( game_field )
	{
		mLandscapes = reader.Read( mLevel );
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

		for( const auto landscape: mLandscapes )
		{
			auto sprite = mSpriteManager.Get( landscape );
			sf::Vector2f sprite_size = {static_cast<float>(sprite.getTextureRect().width) * sprite.getScale().x,
										static_cast<float>(sprite.getTextureRect().height) * sprite.getScale().y};

			sprite.setPosition( {mGameField.left + shift.x, mGameField.top + shift.y} );
			target.draw( sprite );
			shift.x += sprite_size.x;
			if( shift.x + sprite_size.x >= mGameField.width + mGameField.left )
			{
				shift.y += sprite_size.y;
				shift.x = 0;
			}
		}
	}
}