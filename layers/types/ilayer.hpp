//
// Created by claif on 16.01.2022.
//

#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>


namespace layer::types
{
	class ILayer
	{
	public:
		~ILayer() = default;

		virtual sf::Sprite GetSprite() = 0;
	};

	using ILayerPtr = std::shared_ptr < ILayer >;
}