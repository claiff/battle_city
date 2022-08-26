//
// Created by claiff on 19.05.22.
//

#include "landscape.hpp"
#include "resource/texture_getter.hpp"

namespace resource::builder
{

	Manager < Id::Landscape > Landscape::Build() const
	{
		static const sf::Vector2i BACKGROUND_POSITION = {336, 32};
		static const sf::Vector2i FLAG_POSITION = {304, 32};

		sf::Vector2i LANDSCAPE_SIZE = GetLandscapeSize();

		Manager < Id::Landscape > result{TextureGetter::Get()};

		auto default_size = GetDefaultSpriteSize();
		result.Add( Id::Landscape::None, {BACKGROUND_POSITION, LANDSCAPE_SIZE}, GetScale( LANDSCAPE_SIZE ));
		result.Add( Id::Landscape::Flag_1, {FLAG_POSITION, LANDSCAPE_SIZE}, GetScale( LANDSCAPE_SIZE ));

		ApplyBricks( result );
		ApplyIrons( result );

		return result;
	}

	void Landscape::ApplyIrons( Manager <Id::Landscape>& result ) const
	{
		static const sf::Vector2i IRON_1_POSITION = {256, 16};
		static const sf::Vector2i IRON_2_POSITION = {272, 16};
		static const sf::Vector2i IRON_3_POSITION = {288, 16};
		static const sf::Vector2i IRON_4_POSITION = {304, 16};
		static const sf::Vector2i IRON_5_POSITION = {320, 16};

		auto landscape_size = GetLandscapeSize();
		result.Add( Id::Landscape::Iron_1, {IRON_1_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Iron_2, {IRON_2_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Iron_3, {IRON_3_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Iron_4, {IRON_4_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Iron_5, {IRON_5_POSITION, landscape_size}, GetScale( landscape_size ));
	}

	sf::Vector2i Landscape::GetLandscapeSize() const
	{
		static const sf::Vector2i LANDSCAPE_SIZE = {16, 16};
		return LANDSCAPE_SIZE;
	}

	void Landscape::ApplyBricks( Manager < Id::Landscape >& result ) const
	{
		static const sf::Vector2i BRICK_1_POSITION = {256, 0};
		static const sf::Vector2i BRICK_2_POSITION = {272, 0};
		static const sf::Vector2i BRICK_3_POSITION = {288, 0};
		static const sf::Vector2i BRICK_4_POSITION = {304, 0};
		static const sf::Vector2i BRICK_5_POSITION = {320, 0};
		static const sf::Vector2i BRICK_6_POSITION = {336, 0};
		static const sf::Vector2i BRICK_7_POSITION = {352, 0};

		auto landscape_size = GetLandscapeSize();

		result.Add( Id::Landscape::Brick_1, {BRICK_1_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_2, {BRICK_2_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_3, {BRICK_3_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_4, {BRICK_4_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_5, {BRICK_5_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_6, {BRICK_6_POSITION, landscape_size}, GetScale( landscape_size ));
		result.Add( Id::Landscape::Brick_7, {BRICK_7_POSITION, landscape_size}, GetScale( landscape_size ));
	}
}