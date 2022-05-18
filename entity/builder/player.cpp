//
// Created by claiff on 16.05.22.
//

#include "player.hpp"
#include "entity/player.hpp"
#include "utils/consistent_registrator.hpp"
#include "entity/animate_rectangle_shape.hpp"
#include "projectile.hpp"

namespace entity::builder
{
	types::ITankEntityPtr
	Player::Build( resource::Manager const& manager, layer::types::LayerPtr const& collisions ) const
	{
		auto player_anim_1 = manager.Get( resource::Id::PlayerYellow_1 );
		auto player_anim_2 = manager.Get( resource::Id::PlayerYellow_2 );

		auto view = GetPlayerShape( player_anim_1 );

		auto registrator = std::make_shared < utils::ConsistentRegistrator < sf::Sprite>>();
		registrator->Add( player_anim_1 );
		registrator->Add( player_anim_2 );

		AnimateRectangleShape animate_player_view{view, registrator, 10};

		entity::builder::Projectile projectile_builder{manager, types::MovementInfo{10, 35}};
		return std::make_shared < entity::Player >( animate_player_view, projectile_builder, collisions,
													types::MovementInfo{5, 35} );
	}

	sf::RectangleShape Player::GetPlayerShape( sf::Sprite const& sprite ) const
	{
		sf::RectangleShape result;
		result.setTexture( sprite.getTexture());
		result.setPosition( {700, 200} );
		result.setTextureRect( sprite.getTextureRect());
		result.setSize( {static_cast<float>(sprite.getTextureRect().width * sprite.getScale().x),
						 static_cast<float>(sprite.getTextureRect().height) * sprite.getScale().y} );
		return result;
	}

}