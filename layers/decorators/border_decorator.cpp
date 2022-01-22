//
// Created by claif on 19.01.2022.
//

#include "border_decorator.hpp"
#include "resource/png/manager.hpp"
#include "resource/ini/ini_reader.hpp"

namespace layer
{
	Border::Border( types::ILayerPtr const& layer )
			: IDecorator( layer )
	{
		if( !mRenderTexture.create( 800, 600 ))
		{
			throw "IDecorator::IDecorator Невозможно отрисовать mRenderTexture";
		}
	}

	sf::Sprite Border::GetSprite()
	{
		auto decorator_sprite = types::IDecorator::GetSprite();
		auto border_sprite = resource::png::Manager::GetBorderdSprite();

		mRenderTexture.clear();
		mRenderTexture.draw( decorator_sprite );
		FillBorder( border_sprite );
		mRenderTexture.display();

		return sf::Sprite{mRenderTexture.getTexture()};
	}

	void Border::FillBorder( sf::Sprite& sprite )
	{
		static constexpr int ZERO_POSITION = 0;

		static constexpr int UP_HOR_LINE_WIDTH = 1;
		static constexpr int DOWN_HOR_LINE_WIDTH = 1;
		static constexpr int LEFT_VERT_LINE_WIDTH = 2;
		static constexpr int RIGHT_VERT_LINE_WIDTH = 4;

		auto count_sprite_in_row = std::stoi( resource::ini::IniReader::GetValue( "count_sprite_in_row" ));
		auto count_sprite_in_column = std::stoi( resource::ini::IniReader::GetValue( "count_sprite_in_column" ));

		auto down_hor_line_position = count_sprite_in_column - DOWN_HOR_LINE_WIDTH;
		auto right_ver_line_position = count_sprite_in_row - RIGHT_VERT_LINE_WIDTH;

		DrawHorizontalLine( ZERO_POSITION, ZERO_POSITION, UP_HOR_LINE_WIDTH, sprite );
		DrawHorizontalLine( ZERO_POSITION, down_hor_line_position, DOWN_HOR_LINE_WIDTH, sprite );
		DrawVerticalLine( ZERO_POSITION, ZERO_POSITION, LEFT_VERT_LINE_WIDTH, sprite );
		DrawVerticalLine( right_ver_line_position, ZERO_POSITION, RIGHT_VERT_LINE_WIDTH, sprite );
	}

	void Border::DrawHorizontalLine( float x, float y, int height, sf::Sprite& sprite )
	{
		auto count_sprite_in_row = std::stoi( resource::ini::IniReader::GetValue( "count_sprite_in_row" ));
		SetPosition( x, y, sprite );
		for( auto local_y = 0; local_y < height; local_y++ )
		{
			for( auto local_x = 0; local_x < count_sprite_in_row; local_x++ )
			{
				mRenderTexture.draw( sprite );
				ShiftSpriteX( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite, x );
		}
	}

	void Border::DrawVerticalLine( float x, float y, int width, sf::Sprite& sprite )
	{
		auto count_sprite_in_column = std::stoi( resource::ini::IniReader::GetValue( "count_sprite_in_column" ));
		SetPosition( x, y, sprite );
		for( auto local_y = 0; local_y < count_sprite_in_column; local_y++ )
		{
			for( auto local_x = 0; local_x < width; local_x++ )
			{
				mRenderTexture.draw( sprite );
				ShiftSpriteX( sprite );
			}
			ShiftSpriteY( sprite );
			ResetSpriteX( sprite, x );
		}
	}

}


