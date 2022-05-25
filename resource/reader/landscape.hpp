//
// Created by claiff on 23.05.22.
//


#pragma once

#include <string>
#include <vector>

#include "SFML/include/SFML/Graphics/RectangleShape.hpp"

#include "resource/manager.hpp"
#include "resource/parser/landscape.hpp"

namespace resource::reader
{
	using ReadingResult = std::list < resource::Id::Landscape >;

	class Landscape
	{
	public:
		Landscape( std::string const& folder, resource::parser::Landscape const& parser );
		~Landscape() = default;

		[[nodiscard]] ReadingResult Read( unsigned int level ) const;
	private:
		[[nodiscard]] std::ifstream GetStreamFile( unsigned int level ) const;
		[[nodiscard]] std::string GetLevelFilePath( unsigned int level ) const;
		void InsertParseData( ReadingResult& result, std::string const& read_line ) const;

		std::string mFolder;
		resource::parser::Landscape mParser;
	};
}

