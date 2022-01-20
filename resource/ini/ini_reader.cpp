//
// Created by claif on 16.01.2022.
//
#include <fstream>

#include "ini_reader.hpp"
#include "parser.hpp"

namespace resource::ini
{
	ParametersSet IniReader::mParameters {};
	bool IniReader::mIsInit = false;

	std::string IniReader::GetValue( std::string const& parameter ) noexcept
	{
		if( !mIsInit )
		{
			InitReader();
		}
		try
		{
			return mParameters.at( parameter );
		}
		catch( std::exception& )
		{
			return {};
		}
	}

	void IniReader::InitReader()
	{
		static const std::string PATH = R"(C:\Users\claif\Documents\projects\battle_city\settings.ini)";

		std::string line;
		std::ifstream ini_file( PATH );

		if( !ini_file.is_open())
		{
			throw "IniReader::IniReader Отсутствует ini файл";
		}

		while( getline( ini_file, line ))
		{
			ProcessLine( line );
		}
		ini_file.close();
	}

	void IniReader::ProcessLine( std::string const& line )
	{
		Parser parser;
		auto result = parser.Parse( line );
		if( !result )
		{
			return;
		}
		mParameters.emplace( *result );
	}
}