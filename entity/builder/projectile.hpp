//
// Created by claiff on 17.05.22.
//


#pragma once

#include "entity/projectile.hpp"
#include "resource/manager.hpp"

namespace entity::builder
{
	class Projectile
	{
	public:
		Projectile( resource::Manager const& manager, types::MovementInfo const& move_info );
		~Projectile() = default;

		[[nodiscard]] entity::Projectile Build( sf::Vector2f const& position, types::Direction direction ) const;
	private:
		void FixApplyViewPosition( const sf::Vector2f& position, sf::Sprite const& sprite,
								   types::Direction direction, sf::RectangleShape& result ) const;
		void ApplyViewSize( sf::RectangleShape& result, const sf::Sprite& sprite ) const;

		resource::Manager mManager;
		types::MovementInfo mMoveInfo;
		[[nodiscard]] sf::RectangleShape GetView( sf::Vector2f const& position, types::Direction direction ) const;

	};
}
