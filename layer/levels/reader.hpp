//
// Created by claiff on 23.05.22.
//


#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>

#include "resource/manager.hpp"
#include "resource/landscape_parser.hpp"

namespace layer::levels
{
	using ReadingResult = std::list < resource::Id::Landscape >;

	class Reader
	{
	public://TODO обобщить
		Reader( std::string const& folder, resource::LandscapeParser const& parser );
		~Reader() = default;

		ReadingResult Read( unsigned int level ) const;
	private:
		std::string mFolder;
		resource::LandscapeParser mParser;
	};
}

