//
// Created by claiff on 17.05.22.
//

#include "projectile.hpp"
#include "utils/direction_helper.hpp"

namespace entity::builder
{
	Projectile::Projectile( const resource::Manager& manager, const types::MovementInfo& move_info )
			: mManager( manager )
			, mMoveInfo( move_info )
	{

	}

	entity::Projectile Projectile::Build( sf::Vector2f const& position, types::Direction direction ) const
	{
		return entity::Projectile{GetView( position, direction ), {mMoveInfo, direction}};
	}

	sf::RectangleShape Projectile::GetView( sf::Vector2f const& position, types::Direction direction ) const
	{
		sf::RectangleShape result;
		auto sprite = mManager.Get( resource::Id::Projectile );
		auto sprite_size = sprite.getTextureRect().getSize();
		auto sprite_scale = sprite.getScale();

		result.setSize( {static_cast<float>(sprite_size.x) * sprite_scale.x,
						 static_cast<float>(sprite_size.y) * sprite_scale.y} );
		result.setPosition( position );
		result.setTextureRect( sprite.getTextureRect());
		result.setTexture( sprite.getTexture());
		result.setRotation( utils::DirectionHelper::DirectionToAngle( direction ));

		return result;
	}
}