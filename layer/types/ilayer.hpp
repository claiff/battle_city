//
// Created by claiff on 27.04.22.
//

#pragma once

#include <memory>

#include <SFML/include/SFML/Graphics/Drawable.hpp>

namespace layer::types
{
class ILayer : public sf::Drawable
	{
	public:
		~ILayer() override = default;

		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override
		{}
	};

	using LayerPtr = std::shared_ptr < ILayer >;
}