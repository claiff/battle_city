//
// Created by claif on 19.01.2022.
//

#include "idecorator.hpp"

namespace layer::types
{
	IDecorator::IDecorator( ILayerPtr const& layer )
			: mLayer( layer )
	{

	}

	sf::Sprite IDecorator::GetSprite()
	{
		return mLayer->GetSprite();
	}

}