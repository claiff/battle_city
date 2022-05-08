//
// Created by claiff on 08.05.22.
//

#pragma once

#include <memory>

#include <SFML/include/SFML/Graphics/Drawable.hpp>

namespace entity::types
{
	class IEntity
			: public sf::Drawable
	{
	public:
		~IEntity() override = default;

		virtual void Move( sf::Vector2f const& step ) = 0;
		virtual sf::Vector2f GetPosition() const = 0;
		virtual void Fire() = 0;
	};

	using IEntityPtr = std::shared_ptr < IEntity >;
}