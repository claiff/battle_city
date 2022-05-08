//
// Created by claiff on 27.04.22.
//

#include <SFML/Graphics/Texture.hpp>

#include "sprite.hpp"
#include "resource/ini_reader.hpp"

namespace resource::builder
{
	static const sf::Vector2i DEFAULT_SIZE = {8, 8};
	//
	// Public methods
	//

	Manager Sprite::Build() const
	{

		static const sf::Vector2i BACKGROUND_POSITION = {336, 0};
		static const sf::Vector2i BORDER_POSITION = {368, 0};
		static const sf::Vector2i PLAYER_POSITION = {1, 2};
		static const sf::Vector2i PLAYER_SIZE = {13, 13};
		static const std::string TEXTURE_PATH = "../../battle_city/media/general_sprites.png";

		Manager result{TEXTURE_PATH};

		result.Add( resource::Id::Background, {BACKGROUND_POSITION, DEFAULT_SIZE}, GetScale( DEFAULT_SIZE ));
		result.Add( resource::Id::Border, {BORDER_POSITION, DEFAULT_SIZE}, GetScale( DEFAULT_SIZE ) );
		result.Add( resource::Id::Player, {PLAYER_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ) );
		return result;
	}

	//
	// Private methods
	//

	sf::Vector2f Sprite::GetScale( sf::Vector2i const& sprite_size ) const
	{
		auto sprite_size_on_window = GetSpriteSizeOnWindow();
		auto scale_x = sprite_size_on_window.x / sprite_size.x;
		auto scale_y = sprite_size_on_window.y / sprite_size.y;
		return {scale_x, scale_y};
	}

	sf::Vector2f Sprite::GetSpriteSizeOnWindow() const
	{
		auto window_size = GetWindowSize();
		auto count_sprite_in_row = std::stoi( IniReader::GetValue( "count_sprite_in_row" ));
		auto count_sprite_in_column = std::stoi( IniReader::GetValue( "count_sprite_in_column" ));

		auto width = static_cast<float>(window_size.x) / count_sprite_in_row;
		auto height = static_cast<float>(window_size.y) / count_sprite_in_column;
		return {width, height};
	}

	sf::Vector2i Sprite::GetWindowSize() const
	{
		//TODO Возможно параметр нужно сделать не string
		auto window_width = std::stoi( IniReader::GetValue( "default_window_width" ));
		auto height_width = std::stoi( IniReader::GetValue( "default_window_height" ));
		return {window_width, height_width};
	}


}