//
// Created by claiff on 08.05.22.
//


#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "types/ilayer.hpp"
#include "types/idecorator.hpp"
#include "resource/manager.hpp"

namespace layer
{
	class Border
			: public types::IDecorator < types::ILayer >
	{
	public:
		explicit Border( resource::Manager const& sprite_manager );
		~Border() override = default;

		void draw( sf::RenderTarget& target, const sf::RenderStates& states ) const override;
		types::CollisionsSet GetCollisions( sf::FloatRect const& rect ) override;
	private:
		void ApplyBorderUp( sf::Sprite const& sprite );
		sf::Vector2f GetSizeUpBorder( sf::Sprite const& sprite ) const;

		void ApplyBorderRight( sf::Sprite const& sprite );
		sf::Vector2f GetPositionRightBorder( sf::Sprite const& sprite ) const;
		sf::Vector2f GetSizeRightBorder( sf::Vector2f const& position, sf::Sprite const& sprite ) const;

		void ApplyBorderDown( sf::Sprite const& sprite );
		sf::Vector2f GetPositionDownBorder( sf::Sprite const& sprite ) const;
		sf::Vector2f GetSizeDownBorder( sf::Vector2f const& position, sf::Sprite const& sprite ) const;

		void ApplyBorderLeft( sf::Sprite const& sprite );
		sf::Vector2f GetSizeLeftBorder( sf::Sprite const& sprite ) const;

		void ApplyTexture( sf::RectangleShape& rect_shape, sf::Sprite const& sprite );
		sf::Vector2f GetWindowSize() const;

		bool GetIntersection( sf::RectangleShape const& border, sf::FloatRect const& rect ) const;

		sf::RectangleShape mUp;
		sf::RectangleShape mRight;
		sf::RectangleShape mDown;
		sf::RectangleShape mLeft;
	};

}