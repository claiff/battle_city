//
// Created by claif on 19.01.2022.
//

#pragma once

#include "ilayer.hpp"

namespace layer::types
{
	class IDecorator
			: public ILayer
	{
	public:
		explicit IDecorator( ILayerPtr const& layer );
		virtual ~IDecorator() = default;
		sf::Sprite GetSprite() override;
	protected:
		ILayerPtr mLayer;

	};
}