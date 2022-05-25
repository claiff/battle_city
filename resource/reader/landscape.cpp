//
// Created by claiff on 23.05.22.
//

#include <fstream>

#include "landscape.hpp"

namespace resource::reader
{
	//
	//Constructors
	//

	Landscape::Landscape( std::string const& folder, resource::parser::Landscape const& parser )
			: mFolder( folder )
			, mParser( parser )
	{
	}

	//
	//Public methods
	//

	ReadingResult Landscape::Read( unsigned int level ) const
	{
		ReadingResult result;

		std::string read_line;

		auto level_file = GetStreamFile( level );
		while( getline( level_file, read_line ))
		{
			InsertParseData( result, read_line );
		}
		level_file.close();
		return result;
	}

	//
	//Private methods
	//

	std::ifstream Landscape::GetStreamFile( unsigned int level ) const
	{
		std::ifstream result{GetLevelFilePath( level )};
		if( !result.is_open())
		{
			throw "Reader::Read Отсутствует файл level_";
		}
		return result;
	}

	std::string Landscape::GetLevelFilePath( unsigned int level ) const
	{
		//TODO путь
		static const std::string PATH = R"(../../battle_city/)";
		static const std::string DEFAULT_EXTENSION = ".txt";

		return PATH + mFolder + std::to_string( level ) + DEFAULT_EXTENSION;
	}

	void Landscape::InsertParseData( ReadingResult& result, std::string const& read_line ) const
	{
		auto parse_data = mParser.Parse( read_line );
		result.insert( result.end(), parse_data.begin(), parse_data.end());
	}
}