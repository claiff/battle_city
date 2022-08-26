//
// Created by claif on 16.01.2022.
//
#include <fstream>

#include "ini.hpp"
#include "resource/parser/ini.hpp"

namespace resource::reader
{
	ParametersSet Ini::mParameters {};
	bool Ini::mIsInit = false;

	std::string Ini::GetValue( std::string const& parameter ) noexcept
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

	void Ini::InitReader()
	{
		static const std::string PATH = R"(../battle_city/settings.ini)";

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

	void Ini::ProcessLine( std::string const& line )
	{
		auto result = resource::parser::Ini{}.Parse( line );
		if( !result )
		{
			return;
		}
		mParameters.emplace( *result );
	}
}