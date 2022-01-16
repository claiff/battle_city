//
// Created by claif on 16.01.2022.
//

#include "picture_builder.hpp"
#include <chrono>
#include <mingw.thread.h>

namespace picture
{

	PictureBuilder::PictureBuilder( sf::Sprite& draw_sprite )
			: mDrawSprite( draw_sprite )
	{

	}

	void PictureBuilder::ReDraw()
	{
		using namespace std::chrono_literals;

		std::this_thread::sleep_for( 2000ms );
		std::lock_guard < std::mutex > lock( mSpriteMutex );
		mDrawSprite.setColor( sf::Color::Cyan );
	}

}