//
// Created by claiff on 12.05.22.
//

#include "rect_sprite.hpp"

namespace resource
{
	sf::Vector2f RectSprite::GetSize() const
	{
		auto rotation = getRotation();
		if( rotation == sf::degrees( 0 ) || rotation == sf::degrees( 180 ))
		{
			return {static_cast<float>(getTextureRect().width * getScale().x ),
					static_cast<float>(getTextureRect().height * getScale().y)};
		}
		else
		{
			return {static_cast<float>(getTextureRect().height * getScale().y),
					static_cast<float>(getTextureRect().width * getScale().x )};
		}
	}

}