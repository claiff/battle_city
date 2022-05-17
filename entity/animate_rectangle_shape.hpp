//
// Created by claiff on 17.05.22.
//


#pragma once

#include <SFML/include/SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "utils/types/registrator.hpp"
#include "utils/types/ipolicy.hpp"

namespace entity
{
	class AnimateRectangleShape
			: public sf::Drawable
	{
		using RegistratorType = utils::types::RegistratorPtr < sf::Sprite >;
	public:
		AnimateRectangleShape( sf::RectangleShape const& view, RegistratorType const& registrator,
							   unsigned int reload_ms );
		~AnimateRectangleShape() override = default;

		void Move( sf::Vector2f const& step );
		void SetRotation( sf::Angle const& angle );
		sf::Angle GetRotation() const;
		sf::FloatRect GetPlayerRect() const;
		void SetAnimation( bool value );
	protected:
		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override;
	private:
		void FixSprite();
		void ApplyNewView() const;

		mutable sf::RectangleShape mView;
		RegistratorType mRegistrator;
		utils::types::IPolicyPtr mTimerPolicy;
		bool mIsEnableAnimation;
	};
} // entity
