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

	class IEntity
			: public sf::Drawable
	{
	public:
		~IEntity() override = default;

		virtual void Fire() = 0;
		virtual void Update() = 0;
		virtual void StartMove( Direction direction ) = 0;
		virtual void StopMove( Direction direction ) = 0;

	public:
		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override
		{
		}
	};

	using IEntityPtr = std::shared_ptr < IEntity >;
}