//
// Created by claiff on 16.05.22.
//


#pragma once

#include "entity/types/itank_entity.hpp"
#include "resource/manager.hpp"
#include "layer/types/ilayer.hpp"
#include "entity/player.hpp"
#include "utils/types/registrator.hpp"

namespace entity::builder
{
	class Player
	{
	public:
		Player() = default;
		~Player() = default;

		[[nodiscard]] types::ITankEntityPtr
		Build( resource::Manager < resource::Id::AllyTank > const& ally_tank_manager,
			   layer::types::LayerPtr const& collisions ) const;

	private:

		TankInfo GetNormalTankInfo( resource::Manager < resource::Id::AllyTank > const& manager ) const;
		TankInfo GetLightTankInfo( resource::Manager < resource::Id::AllyTank > const& manager ) const;
		TankInfo GetMediumTankInfo( resource::Manager < resource::Id::AllyTank > const& manager ) const;
		TankInfo GetHeavyTankInfo( resource::Manager < resource::Id::AllyTank > const& manager ) const;

		utils::types::RegistratorPtr < sf::Sprite >
		GetRegistrator( std::pair < sf::Sprite, sf::Sprite > const& sprites ) const;

		[[nodiscard]] sf::RectangleShape GetPlayerShape( sf::Sprite const& sprite ) const;
		TankInfoRegistrator
		GetTankInfoRegistrator( const resource::Manager < resource::Id::AllyTank >& ally_tank_manager ) const;
		Projectile GetProjectileBuilder( const resource::Manager < resource::Id::AllyTank >& ally_tank_manager ) const;
	};
}

