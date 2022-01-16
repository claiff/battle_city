//
// Created by claif on 16.01.2022.
//

#include "ini_reader.hpp"
#include <fstream>

namespace resource::ini
{
	IniReader::IniReader( Parser const& parser, std::string const& path )
	{
		std::string line;
		std::ifstream ini_file( path );

		if( !ini_file.is_open())
		{
			throw "IniReader::IniReader Отсутствует ini файл";
		}

		while( getline( ini_file, line ))
		{
			ProcessLine( parser, line );
		}
		ini_file.close();
	}

	std::string IniReader::GetValue( std::string const& parameter ) const noexcept
	{
		try
		{
			return mParameters.at( parameter );
		}
		catch( std::exception& )
		{
			return {};
		}
	}

	void IniReader::ProcessLine( Parser const& parser, const std::string& line )
	{
		auto result = parser.Parse(line);
		if( !result )
		{
			return;
		}
		mParameters.emplace( *result );
	}
}