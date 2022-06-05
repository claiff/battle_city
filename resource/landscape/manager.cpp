//
// Created by claiff on 27.05.22.
//

#include "manager.hpp"
#include "brick.hpp"
#include "resource/reader/ini.hpp"

namespace resource::landscape
{
	Manager::Manager( sf::Texture const& texture )
			: mTexture( texture )
	{

	}

	void Manager::Add( Id::Landscape id, sf::IntRect const& rect_texture )
	{
		auto result = mResource.insert( std::make_pair( id, std::move( rect_texture )));
		assert( result.second );
	}

	types::ILandscapePtr Manager::Get( Id::Landscape id ) const
	{
		auto result = GetTemplate( id );

		result->setTexture( &mTexture );
		result->setTextureRect( GetIntRect( id ));
		result->setSize( GetShapeSize());

		return result;
	}

	types::ILandscapePtr Manager::GetTemplate( Id::Landscape id ) const
	{
		switch( id )
		{
			case Id::Landscape::None:
				return std::make_shared <Brick>();
			case Id::Landscape::Brick:
				return std::make_shared <Brick>();
			case Id::Landscape::Iron:
				return std::make_shared <Brick>();
			default:
				return std::make_shared <Brick>();
		}
	}

	sf::IntRect const& Manager::GetIntRect( Id::Landscape id ) const
	{
		auto find = mResource.find( id );
		if( find == mResource.end())
		{
			find = mResource.find( id );
		}
		assert( find != mResource.end());
		return find->second;
	}

//TODO Наверно в общее
	sf::Vector2f Manager::GetShapeSize() const
	{
		auto window_size = GetWindowSize();
		auto count_sprite_in_row = std::stoi( reader::Ini::GetValue( "count_sprite_in_row" ));
		auto count_sprite_in_column = std::stoi( reader::Ini::GetValue( "count_sprite_in_column" ));

		auto width = static_cast<float>(window_size.x) / (count_sprite_in_row*2);
		auto height = static_cast<float>(window_size.y) / (count_sprite_in_column*2);
		return {width, height};
	}

	sf::Vector2i Manager::GetWindowSize() const
	{
		//TODO Возможно параметр нужно сделать не string
		auto window_width = std::stoi( reader::Ini::GetValue( "default_window_width" ));
		auto height_width = std::stoi( reader::Ini::GetValue( "default_window_height" ));
		return {window_width, height_width};
	}
}