//
// Created by claiff on 08.05.22.
//

#pragma once

#include <memory>

#include <SFML/include/SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace entity::types
{
	enum class Direction
	{
		Up,
		Down,
		Right,
		Left
	};

	struct MovementInfo
	{
		float step;
		unsigned int period_ms;
	};

	class IEntity
			: public sf::Drawable
	{
	public:
		~IEntity() override = default;

		virtual void Update() = 0;
	};

	using IEntityPtr = std::shared_ptr < IEntity >;
}