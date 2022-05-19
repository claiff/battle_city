//
// Created by claiff on 19.05.22.
//

#include "border.hpp"

namespace resource::builder
{

	Manager < Id::Border > Border::Build() const
	{
		static const sf::Vector2i BORDER_POSITION = {368, 0};

		Manager < Id::Border > result{GetTexturePath()};

		auto default_size = GetDefaultSpriteSize();
		result.Add( Id::Border::Background, {BORDER_POSITION, default_size}, GetScale( default_size ));

		return result;
	}
}