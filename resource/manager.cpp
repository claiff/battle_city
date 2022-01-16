//
// Created by claif on 16.01.2022.
//

#include "manager.hpp"

namespace texture
{
	sf::Texture Manager::mTextureSet = {};

	Manager::Manager()
	{
		//FIXME normal path
		static const std::string PATH = R"(C:\Users\claif\Documents\projects\battle_city\resource\png)";
		mTextureSet.loadFromFile( PATH );
	}

	sf::Sprite Manager::GetBackGroundSprite()
	{
		sf::Sprite result;
		result.setTexture(mTextureSet);
		result.setTextureRect( {336, 0, 8, 8} );
		return result;
	}
}