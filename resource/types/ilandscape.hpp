//
// Created by claiff on 27.05.22.
//

#pragma once

#include <memory>

#include <SFML/Graphics/RectangleShape.hpp>

namespace resource::types
{
	class ILandscape
			: public sf::RectangleShape
	{
	public:
		~ILandscape() override = default;
	};

	using ILandscapePtr = std::shared_ptr < ILandscape >;
}