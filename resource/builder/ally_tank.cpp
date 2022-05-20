//
// Created by claiff on 27.04.22.
//

#include <SFML/Graphics/Texture.hpp>

#include "ally_tank.hpp"
#include "resource/texture_getter.hpp"

namespace resource::builder
{

	//
	// Public methods
	//

	Manager < Id::AllyTank > AllyTank::Build() const
	{
		//TODO Название танка NORMAL так се
		static const sf::Vector2i NORMAL_ANIM_1_POSITION = {1, 2};
		static const sf::Vector2i NORMAL_ANIM_2_POSITION = {17, 2};
		static const sf::Vector2i LIGHT_ANIM_1_POSITION = {1, 16};
		static const sf::Vector2i LIGHT_ANIM_2_POSITION = {17, 16};
		static const sf::Vector2i MEDIUM_ANIM_1_POSITION = {1, 32};
		static const sf::Vector2i MEDIUM_ANIM_2_POSITION = {17, 32};
		static const sf::Vector2i HEAVY_ANIM_1_POSITION = {1, 49};
		static const sf::Vector2i HEAVY_ANIM_2_POSITION = {17, 49};
		static const sf::Vector2i PLAYER_SIZE = {13, 13};
		static const sf::Vector2i PROJECTILE_POSITION = {323, 102};
		static const sf::Vector2i PROJECTILE_SIZE = {3, 4};

		Manager < Id::AllyTank > result{TextureGetter::Get()};

		result.Add( Id::AllyTank::NormalYellow_1, {NORMAL_ANIM_1_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::NormalYellow_2, {NORMAL_ANIM_2_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::LightYellow_1, {LIGHT_ANIM_1_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::LightYellow_2, {LIGHT_ANIM_2_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::MediumYellow_1, {MEDIUM_ANIM_1_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::MediumYellow_2, {MEDIUM_ANIM_2_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::HeavyYellow_1, {HEAVY_ANIM_1_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::HeavyYellow_2, {HEAVY_ANIM_2_POSITION, PLAYER_SIZE}, GetScale( PLAYER_SIZE ));
		result.Add( Id::AllyTank::Projectile, {PROJECTILE_POSITION, PROJECTILE_SIZE}, GetScale( PLAYER_SIZE ));
		return result;
	}

	//
	// Private methods
	//




}