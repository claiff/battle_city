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
		ApplyViewSize( result, sprite );

		FixApplyViewPosition( position, sprite, direction, result );

		result.setTextureRect( sprite.getTextureRect());
		result.setTexture( sprite.getTexture());
		result.setRotation( utils::DirectionHelper::DirectionToAngle( direction ));

		return result;
	}

	void Projectile::FixApplyViewPosition( sf::Vector2f const& position, sf::Sprite const& sprite,
										   types::Direction direction,
										   sf::RectangleShape& result ) const
	{
		auto sprite_scale = sprite.getScale();
		auto sprite_texture_rect = sprite.getTextureRect();
		//auto step = utils::DirectionHelper::StepOnDirection( direction, 1, 1 );
		sf::Vector2f projectile_size = {sprite_texture_rect.width * sprite_scale.x,
										sprite_texture_rect.height * sprite_scale.y};

		if( direction == types::Direction::Up )
		{
			result.setPosition(
					{position.x - (projectile_size.x / 2), position.y - projectile_size.y} );
		}
		if( direction == types::Direction::Right )
		{
			result.setPosition( {position.x + projectile_size.x, position.y - (projectile_size.y / 2)} );
		}
		if( direction == types::Direction::Down )
		{
			result.setPosition( {position.x + (projectile_size.x / 2), position.y + projectile_size.y} );
		}
		if( direction == types::Direction::Left )
		{
			result.setPosition( {position.x - projectile_size.x, position.y + (projectile_size.y / 2)} );
		}
	}

	void Projectile::ApplyViewSize( sf::RectangleShape& result, sf::Sprite const& sprite ) const
	{
		auto sprite_size = sprite.getTextureRect().getSize();
		auto sprite_scale = sprite.getScale();

		result.setSize( {static_cast<float>(sprite_size.x) * sprite_scale.x,
						 static_cast<float>(sprite_size.y) * sprite_scale.y} );
	}
}