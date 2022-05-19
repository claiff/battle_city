//
// Created by claiff on 16.05.22.
//

#include "player.hpp"

#include "utils/consistent_registrator.hpp"
#include "utils/continue_registrator.hpp"
#include "entity/animate_rectangle_shape.hpp"
#include "projectile.hpp"

namespace entity::builder
{
	static const types::MovementInfo DEFAULT_MOVE_INFO = {5, 35};
	static const unsigned int DEFAULT_RELOAD_TIME = 10;

	types::ITankEntityPtr
	Player::Build( resource::Manager < resource::Id::AllyTank > const& ally_tank_manager,
				   layer::types::LayerPtr const& collisions ) const
	{
		TankInfoRegistrator tank_info_set = GetTankInfoRegistrator( ally_tank_manager );
		Projectile projectile_builder = GetProjectileBuilder( ally_tank_manager );

		auto result = std::make_shared < entity::Player >( tank_info_set, projectile_builder, collisions );
		return result;
	}

	Projectile
	Player::GetProjectileBuilder( const resource::Manager < resource::Id::AllyTank >& ally_tank_manager ) const
	{
		static const types::MovementInfo DEFAULT_PROJECTILE_INFO = {10, 35};
		Projectile projectile_builder{ally_tank_manager, DEFAULT_PROJECTILE_INFO};
		return projectile_builder;
	}

	TankInfoRegistrator
	Player::GetTankInfoRegistrator( const resource::Manager < resource::Id::AllyTank >& ally_tank_manager ) const
	{
		TankInfoRegistrator tank_info_set;
		tank_info_set.Add( GetLightTankInfo( ally_tank_manager ));
		tank_info_set.Add( GetMediumTankInfo( ally_tank_manager ));
		tank_info_set.Add( GetHeavyTankInfo( ally_tank_manager ));
		return tank_info_set;
	}

	TankInfo Player::GetLightTankInfo( resource::Manager < resource::Id::AllyTank > const& manager ) const
	{
		TankInfo result;

		auto registrator = GetRegistrator( {manager.Get( resource::Id::AllyTank::LightYellow_1 ),
											manager.Get( resource::Id::AllyTank::LightYellow_2 )} );

		result.speed = DEFAULT_MOVE_INFO;
		result.mView = std::make_shared < AnimateRectangleShape >( GetPlayerShape( registrator->Get()), registrator,
																   DEFAULT_RELOAD_TIME );
		result.count_projectiles = 1;
		return result;
	}

	TankInfo Player::GetMediumTankInfo( resource::Manager< resource::Id::AllyTank > const& manager ) const
	{
		TankInfo result;

		auto registrator = GetRegistrator( {manager.Get( resource::Id::AllyTank::MediumYellow_1 ),
											manager.Get( resource::Id::AllyTank::MediumYellow_2 )} );

		result.speed = DEFAULT_MOVE_INFO;
		result.mView = std::make_shared < AnimateRectangleShape >( GetPlayerShape( registrator->Get()),
																   registrator,
																   DEFAULT_RELOAD_TIME );
		result.count_projectiles = 2;
		return result;
	}

	TankInfo Player::GetHeavyTankInfo( resource::Manager< resource::Id::AllyTank > const& manager ) const
	{
		TankInfo result;

		auto registrator = GetRegistrator( {manager.Get( resource::Id::AllyTank::HeavyYellow_1 ),
											manager.Get( resource::Id::AllyTank::HeavyYellow_2 )} );
		result.speed = DEFAULT_MOVE_INFO;
		result.mView = std::make_shared < AnimateRectangleShape >( GetPlayerShape( registrator->Get()),
																   registrator,
																   DEFAULT_RELOAD_TIME );
		result.count_projectiles = 2;
		return result;
	}

	utils::types::RegistratorPtr < sf::Sprite >
	Player::GetRegistrator( std::pair < sf::Sprite, sf::Sprite > const& sprites ) const
	{
		auto registrator = std::make_shared < utils::ConsistentRegistrator < sf::Sprite>>();
		registrator->Add( sprites.first );
		registrator->Add( sprites.second );
		return registrator;
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