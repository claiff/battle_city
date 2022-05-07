//
// Created by claiff on 27.04.22.
//



#include "background.hpp"

#include <utility>
#include "resource/ini_reader.hpp"

namespace layer
{

	Background::Background( resource::Manager const& sprite_manager )
			: mSpriteManager( sprite_manager )
	{

	}

	void Background::draw( sf::RenderTarget& target, const sf::RenderStates& states ) const
	{
		auto sprite = mSpriteManager.Get( resource::Id::Background );

		auto scale = GetScale();
		sprite.setScale( scale );
		sprite.setPosition( {0, 0} );
		target.draw( sprite );
	}

	sf::Vector2f Background::GetScale() const
	{
		auto count_sprite_in_row = std::stoi( resource::IniReader::GetValue( "count_sprite_in_row" ));
		auto count_sprite_in_column = std::stoi( resource::IniReader::GetValue( "count_sprite_in_column" ));
		sf::Vector2f scale = {static_cast<float>(count_sprite_in_row), static_cast<float>(count_sprite_in_column)};
		return scale;
	}
}