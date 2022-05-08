//
// Created by claiff on 27.04.22.
//

#include "background.hpp"
#include "resource/ini_reader.hpp"

namespace layer
{

	Background::Background( resource::Manager const& sprite_manager )
			: mSpriteManager( sprite_manager )
	{

	}

	void Background::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		if( mBase )
		{
			mBase->draw( target, states );
		}
		auto sprite = mSpriteManager.Get( resource::Id::Background );
		SetScaleOnFullWindow( sprite );
		target.draw( sprite );
	}

	void Background::SetScaleOnFullWindow( sf::Sprite& sprite ) const
	{
		auto scale = GetScaleOnWhileWindow();
		auto default_scale = sprite.getScale();
		sprite.setScale( {default_scale.x * scale.x, default_scale.y * scale.y} );
		sprite.setPosition( {0, 0} );
	}

	sf::Vector2f Background::GetScaleOnWhileWindow() const
	{
		auto count_sprite_in_row = std::stoi( resource::IniReader::GetValue( "count_sprite_in_row" ));
		auto count_sprite_in_column = std::stoi( resource::IniReader::GetValue( "count_sprite_in_column" ));
		sf::Vector2f scale = {static_cast<float>(count_sprite_in_row), static_cast<float>(count_sprite_in_column)};
		return scale;
	}
}