//
// Created by claiff on 08.05.22.
//


#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

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
		types::CollisionsSet GetCollisions( sf::Rect<float> const& rect ) override;
	private:
		void DrawHorizontalLines( sf::RenderTarget& target, sf::Sprite const& sprite ) const;
		sf::Sprite GetSpriteUp( sf::Sprite const& sprite, int count_sprite_in_row ) const;
		sf::Sprite GetSpriteDown( sf::Sprite const& sprite, int count_sprite_in_row ) const;
		void DrawVerticalLines( sf::RenderTarget& target, sf::Sprite const& sprite ) const;
		sf::Sprite GetSpriteLeft( sf::Sprite const& sprite, int count_sprite_in_column ) const;
		sf::Sprite GetSpriteRight( sf::Sprite const& sprite, int count_sprite_in_column ) const;
		sf::Rect < float > GetRectContainer() const;

		resource::Manager mSpriteManager;
		bool IsRightSideOut( const sf::Rect < float >& rect, const sf::Rect < float >& background_rect ) const;
		bool IsDownSideOut( const sf::Rect < float >& rect, const sf::Rect < float >& background_rect ) const;
		bool IsUpSideOut( const sf::Rect < float >& rect, const sf::Rect < float >& background_rect ) const;
		bool IsLeftSideOut( const sf::Rect < float >& rect, const sf::Rect < float >& background_rect ) const;
	};

}