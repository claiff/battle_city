//
// Created by claiff on 16.05.22.
//


#pragma once

#include "types/ientity.hpp"
#include "resource/manager.hpp"
#include "layer/types/ilayer.hpp"

namespace entity
{
	class PlayerBuilder
	{
	public:
		PlayerBuilder() = default;
		~PlayerBuilder() = default;

		[[nodiscard]] types::IEntityPtr
		Build( resource::Manager const& manager, layer::types::LayerPtr const& collisions ) const;

	private:
		[[nodiscard]] sf::RectangleShape GetPlayerShape( sf::Sprite const& sprite ) const;
	};
}

