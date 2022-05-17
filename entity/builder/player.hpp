//
// Created by claiff on 16.05.22.
//


#pragma once

#include "entity/types/itank_entity.hpp"
#include "resource/manager.hpp"
#include "layer/types/ilayer.hpp"

namespace entity::builder
{
	class Player
	{
	public:
		Player() = default;
		~Player() = default;

		[[nodiscard]] types::ITankEntityPtr
		Build( resource::Manager const& manager, layer::types::LayerPtr const& collisions ) const;

	private:
		[[nodiscard]] sf::RectangleShape GetPlayerShape( sf::Sprite const& sprite ) const;
	};
}

