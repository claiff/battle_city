//
// Created by claiff on 27.05.22.
//

#include "landscape.hpp"

namespace resource::builder
{
	Landscape::Landscape( reader::Landscape const& reader, sf::FloatRect const& game_field,
						  landscape::Manager const& manager )
			: mReader( reader )
			, mGameField( game_field )
			, mManager( manager )
	{

	}

	BuildResult Landscape::Build( unsigned int level ) const
	{
		BuildResult result;

		auto landscape_ids = mReader.Read( level );
		sf::Vector2f sprite_position = {mGameField.left, mGameField.top};
		for( auto it = landscape_ids.cbegin(); it != landscape_ids.cend(); )
		{
			auto array_landscapes = GetArrayOfLandscapes( it, sprite_position );
			result.push_back( array_landscapes );

			sprite_position.x += array_landscapes.at( 0 )->getSize().x * 2;
			if( sprite_position.x > mGameField.width )
			{
				sprite_position.y += array_landscapes.at( 0 )->getSize().y * 2;
				sprite_position.x = mGameField.left;
			}
		}
		return result;
	}

//TODO Refactor
	ArrayOfLandscapes
	Landscape::GetArrayOfLandscapes( LandscapeConstIterator& it,
									 sf::Vector2f const& start_position ) const
	{
		static constexpr int COUNT_ROW = 2;
		static constexpr int COUNT_COLUMN = 2;

		ArrayOfLandscapes result;
		types::ILandscapePtr shape;
		sf::Vector2f shift{start_position};

		for( auto column = 0; column < COUNT_COLUMN; ++column )
		{
			for( auto row = 0; row < COUNT_ROW; ++row )
			{
				shape = mManager.Get( *it++ );

				shape->setPosition( shift );
				result.at( COUNT_ROW * column + row ) = shape;

				shift.x += shape->getSize().x;
			}
			shift.y += shape->getSize().y;
			shift.x = start_position.x;
		}

		return result;
	}
}