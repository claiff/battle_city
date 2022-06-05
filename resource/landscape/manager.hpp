//
// Created by claiff on 27.05.22.
//


#pragma once

#include <map>

#include "resource/types/ilandscape.hpp"

namespace resource::landscape
{
	namespace Id
	{
		enum class Landscape
		{
			None,
			Flag,
			Flag_Ruined,
			Brick,
			Iron
		};
	}

	class Manager
	{
	public:
		explicit Manager( sf::Texture const& texture );
		~Manager() = default;

		void Add( Id::Landscape id, sf::IntRect const& rect_texture );
		types::ILandscapePtr Get( Id::Landscape id ) const;
	private:
		types::ILandscapePtr GetTemplate( Id::Landscape id ) const;
		const sf::IntRect& GetIntRect( Id::Landscape id ) const;
		sf::Vector2f GetShapeSize( ) const;
		sf::Vector2i GetWindowSize() const;

		sf::Texture const& mTexture;
		std::map < Id::Landscape, sf::IntRect > mResource;
	};
}

