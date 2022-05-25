//
// Created by claiff on 23.05.22.
//

#include <fstream>
#include "reader.hpp"

namespace layer::levels
{
	Reader::Reader( std::string const& folder, resource::LandscapeParser const& parser )
			: mFolder( folder )
			, mParser( parser )
	{
	}

	ReadingResult Reader::Read( unsigned int level ) const
	{
		ReadingResult result;
		//TODO путь
		static const std::string PATH = R"(../../battle_city/)";
		static const std::string DEFAULT_EXTENSION = ".txt";

		std::string line;

		auto full_path = PATH + mFolder + std::to_string( level ) + DEFAULT_EXTENSION;

		std::ifstream level_file( full_path );
		if( !level_file.is_open())
		{
			throw "Reader::Read Отсутствует файл level_";
		}
		while( getline( level_file, line ))
		{
			auto parse_data = mParser.Parse( line );
			result.insert( result.end(), parse_data.begin(), parse_data.end());
		}
		level_file.close();
		return result;
	}
}