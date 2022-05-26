//
// Created by claiff on 23.05.22.
//

#include <SFML/Graphics/RenderTarget.hpp>

#include "landscape.hpp"

namespace layer
{
	Landscape::Landscape( sf::FloatRect const& game_field,
						  const resource::Manager < resource::Id::Landscape >& sprite_manager,
						  resource::reader::Landscape const& reader )
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

		for( const auto& landscape: mLandscapes )
		{
			auto sprite = GetSprite( landscape, shift );
			target.draw( sprite );
			ApplyShift( shift, sprite );
		}
	}

	sf::Sprite Landscape::GetSprite( resource::Id::Landscape landscape, sf::Vector2f const& shift ) const
	{
		auto sprite = mSpriteManager.Get( landscape );
		sprite.setPosition( {mGameField.left + shift.x, mGameField.top + shift.y} );
		return sprite;
	}

	void Landscape::ApplyShift( sf::Vector2f& shift, sf::Sprite const& sprite ) const
	{
		auto sprite_size = GetSpriteSize( sprite );
		shift.x += sprite_size.x;
		if( IsOutXBorder( shift, sprite_size ))
		{
			ApplyNextLine( shift, sprite_size );
		}
	}

	sf::Vector2f Landscape::GetSpriteSize( sf::Sprite const& sprite ) const
	{
		return {static_cast<float>(sprite.getTextureRect().width) * sprite.getScale().x,
				static_cast<float>(sprite.getTextureRect().height) * sprite.getScale().y};
	}

	bool Landscape::IsOutXBorder( const sf::Vector2f& shift, const sf::Vector2f& sprite_size ) const noexcept
	{
		return shift.x + sprite_size.x >= mGameField.width + mGameField.left;
	}

	void Landscape::ApplyNextLine( sf::Vector2f& shift, sf::Vector2f const& sprite_size ) const
	{
		shift.y += sprite_size.y;
		shift.x = 0;
	}
}