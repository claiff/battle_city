//
// Created by claiff on 08.05.22.
//

#include "border.hpp"
#include "resource/ini_reader.hpp"

namespace layer
{
	static const sf::Vector2f ZERO_POSITION = {0, 0};

	//
	//Constructors
	//

	Border::Border( resource::Manager const& sprite_manager )
			: mSpriteManager( sprite_manager )
	{

	}

	//
	//Public methods
	//

	void Border::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		if( mBase )
		{
			mBase->draw( target, states );
		}

		auto sprite = mSpriteManager.Get( resource::Id::Border );

		DrawHorizontalLines( target, sprite );
		DrawVerticalLines( target, sprite );

		target.draw( sprite );
	}

	//
	//Private methods
	//

	void Border::DrawHorizontalLines( sf::RenderTarget& target, sf::Sprite const& sprite ) const
	{
		auto count_sprite_in_row = std::stoi( resource::IniReader::GetValue( "count_sprite_in_row" ));

		auto sprite_up = GetSpriteUp( sprite, count_sprite_in_row );
		auto sprite_down = GetSpriteDown( sprite, count_sprite_in_row );

		target.draw( sprite_up );
		target.draw( sprite_down );
	}

	sf::Sprite Border::GetSpriteUp( sf::Sprite const& sprite, int count_sprite_in_row ) const
	{
		auto result = sprite;
		auto init_scale = sprite.getScale();

		result.setScale( {init_scale.x * count_sprite_in_row, init_scale.y} );
		result.setPosition( ZERO_POSITION );

		return result;
	}

	sf::Sprite
	Border::GetSpriteDown( sf::Sprite const& sprite, int count_sprite_in_row ) const
	{
		static constexpr int ZERO_POSITION_X = 0;

		auto height_width = std::stoi( resource::IniReader::GetValue( "default_window_height" ));
		auto result = sprite;
		auto init_scale = sprite.getScale();
		float sprite_y = height_width - result.getTextureRect().height * init_scale.y;

		result.setScale( {init_scale.x * count_sprite_in_row, init_scale.y} );
		result.setPosition( {ZERO_POSITION_X, sprite_y} );

		return result;
	}

	void Border::DrawVerticalLines( sf::RenderTarget& target, sf::Sprite const& sprite ) const
	{
		auto count_sprite_in_column = std::stoi( resource::IniReader::GetValue( "count_sprite_in_column" ));

		auto sprite_left = GetSpriteLeft( sprite, count_sprite_in_column );
		auto sprite_right = GetSpriteRight( sprite, count_sprite_in_column );

		target.draw( sprite_left );
		target.draw( sprite_right );
	}

	sf::Sprite Border::GetSpriteLeft( sf::Sprite const& sprite, int count_sprite_in_column ) const
	{
		auto result = sprite;
		auto init_scale = sprite.getScale();

		result.setPosition( ZERO_POSITION );
		result.setScale( {init_scale.x, init_scale.y * count_sprite_in_column} );

		return result;
	}

	sf::Sprite Border::GetSpriteRight( sf::Sprite const& sprite, int count_sprite_in_column ) const
	{
		static constexpr int ZERO_POSITION_Y = 0;

		auto window_width = std::stoi( resource::IniReader::GetValue( "default_window_width" ));
		auto result = sprite;
		auto init_scale = sprite.getScale();
		float sprite_x = window_width - sprite.getTextureRect().width * init_scale.x;

		result.setPosition( {sprite_x, ZERO_POSITION_Y} );
		result.setScale( {init_scale.x, init_scale.y * count_sprite_in_column} );

		return result;
	}
}