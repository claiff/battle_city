//
// Created by claiff on 19.05.22.
//

#pragma once

#include "resource/manager.hpp"
#include "resource/ini_reader.hpp"

namespace resource::builder::types
{
	template<typename T>
	class IBuilder
	{
	public:
		virtual ~IBuilder() = default;

		virtual Manager < T > Build() const = 0;
	protected:

		/*!
		\brief Определяет масштабирование спрайта
		*/
		sf::Vector2f GetScale( sf::Vector2i const& sprite_size ) const
		{
			auto sprite_size_on_window = GetSpriteSizeOnWindow();
			auto scale_x = sprite_size_on_window.x / sprite_size.x;
			auto scale_y = sprite_size_on_window.y / sprite_size.y;
			return {scale_x, scale_y};
		}

		sf::Vector2i GetDefaultSpriteSize() const
		{
			static const sf::Vector2i DEFAULT_SIZE = {8, 8};
			return DEFAULT_SIZE;
		}

	private:

		/*!
		\brief Определяет размер спрайта по размеру окна
		*/
		sf::Vector2f GetSpriteSizeOnWindow() const
		{
			auto window_size = GetWindowSize();
			auto count_sprite_in_row = std::stoi( IniReader::GetValue( "count_sprite_in_row" ));
			auto count_sprite_in_column = std::stoi( IniReader::GetValue( "count_sprite_in_column" ));

			auto width = static_cast<float>(window_size.x) / count_sprite_in_row;
			auto height = static_cast<float>(window_size.y) / count_sprite_in_column;
			return {width, height};
		}

		/*!
		\brief Определяет размер окна по файлу settings
		*/
		sf::Vector2i GetWindowSize() const
		{
			//TODO Возможно параметр нужно сделать не string
			auto window_width = std::stoi( IniReader::GetValue( "default_window_width" ));
			auto height_width = std::stoi( IniReader::GetValue( "default_window_height" ));
			return {window_width, height_width};
		}
	};

	template<typename T>
	using IBuilderPtr = std::shared_ptr < IBuilder < T > >;
}