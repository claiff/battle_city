//
// Created by claiff on 27.05.22.
//


#pragma once

#include <vector>
#include <array>

#include <SFML/Graphics/RectangleShape.hpp>

#include "resource/reader/landscape.hpp"
#include "resource/landscape/manager.hpp"

namespace resource::builder
{
	static constexpr unsigned int COUNT_RECTS_IN_ARRAY = 4;
	//Каждый тайл состоит из четырех спрайтов
	using ArrayOfLandscapes = std::array < types::ILandscapePtr , COUNT_RECTS_IN_ARRAY >;
	using BuildResult = std::list < ArrayOfLandscapes >;
	using LandscapeConstIterator = std::list < landscape::Id::Landscape >::const_iterator;

	class Landscape
	{
	public:
		Landscape( resource::reader::Landscape const& reader, sf::FloatRect const& game_field,
				   landscape::Manager const& manager );
		~Landscape() = default;

		BuildResult Build( unsigned int level ) const;
	private:
		ArrayOfLandscapes GetArrayOfLandscapes( LandscapeConstIterator& it,
												sf::Vector2f const& start_position ) const;

		resource::reader::Landscape mReader;
		landscape::Manager mManager;
		sf::FloatRect mGameField;
	};
}

