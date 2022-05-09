//
// Created by claiff on 08.05.22.
//

#pragma once

#include <memory>

#include <SFML/include/SFML/Graphics/Drawable.hpp>

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

		virtual void Move( sf::Vector2f const& step ) = 0;
		virtual sf::Vector2f GetPosition() const = 0;
		virtual void Fire() = 0;
		virtual void Update() = 0;
		virtual void StartMove( Direction direction ) =0;
		virtual void StopMove( ) =0;
	};

	using IEntityPtr = std::shared_ptr < IEntity >;
}