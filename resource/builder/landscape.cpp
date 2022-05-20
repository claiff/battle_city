//
// Created by claiff on 19.05.22.
//

#include "landscape.hpp"
#include "resource/texture_getter.hpp"

namespace resource::builder
{
	Manager < Id::Landscape > Landscape::Build() const
	{
		static const sf::Vector2i BACKGROUND_POSITION = {336, 0};

		Manager < Id::Landscape > result{TextureGetter::Get()};

		auto default_size = GetDefaultSpriteSize();
		result.Add( Id::Landscape::None, {BACKGROUND_POSITION, default_size}, GetScale( default_size ));
		return result;
	}
}