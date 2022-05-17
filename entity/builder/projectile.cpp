//
// Created by claiff on 17.05.22.
//

#include "projectile.hpp"

namespace entity::builder
{
	Projectile::Projectile( const resource::Manager& manager, const types::MovementInfo& move_info )
			: mManager( manager )
			, mMoveInfo( move_info )
	{

	}

	entity::Projectile Projectile::Build( sf::Vector2f const& position, types::Direction direction ) const
	{
		auto view = GetView( position );
		ProjectileInfo projectile_info{};
		projectile_info.direction = direction;
		projectile_info.step = mMoveInfo.step;
		projectile_info.period_ms = mMoveInfo.period_ms;
		return entity::Projectile{view, projectile_info};
	}

	sf::RectangleShape Projectile::GetView( sf::Vector2f const& position ) const
	{
		sf::RectangleShape result;
		auto sprite = mManager.Get( resource::Id::Projectile );

		auto sprite_size = sprite.getTextureRect().getSize();
		result.setSize( {static_cast<float>(sprite_size.x), static_cast<float>(sprite_size.y)} );
		result.setPosition( position );

		result.setTextureRect( sprite.getTextureRect());
		result.setTexture( sprite.getTexture());

		return result;
	}
}