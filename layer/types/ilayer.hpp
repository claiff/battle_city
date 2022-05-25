//
// Created by claiff on 27.04.22.
//

#pragma once

#include <memory>
#include <vector>

#include <SFML/include/SFML/Graphics/Drawable.hpp>
#include <SFML/include/SFML/Graphics/Rect.hpp>

namespace layer::types
{
	class ILayer;

	using LayerPtr = std::shared_ptr < ILayer >;
	using CollisionsSet = std::vector < ILayer* >;

	class ILayer
			: public sf::Drawable
	{
	public:
		~ILayer() override = default;

		void draw( sf::RenderTarget& target, sf::RenderStates const& states ) const override
		{
		}

		[[nodiscard]] virtual CollisionsSet GetCollisions( sf::FloatRect const& rect ) = 0;
	};


}