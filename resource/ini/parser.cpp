//
// Created by claif on 16.01.2022.
//

#include <algorithm>

#include "parser.hpp"

namespace resource::ini
{
	ParseResult Parser::Parse( const std::string& text ) const
	{
		static const std::string SLASH_SIGN = "//";
		static const std::string EQUAL_SIGN = "=";
		static constexpr int FIRST_SYMBOL = 0;

		ParseResult result;

		auto search_text = text.find( SLASH_SIGN );
		if( search_text == FIRST_SYMBOL )
		{
			return std::nullopt;
		}
		search_text = text.find( EQUAL_SIGN );
		if( search_text == std::string::npos )
		{
			return std::nullopt;
		}
		auto first_parameter = text.substr( FIRST_SYMBOL, search_text );
		auto second_parameter = text.substr( search_text + 1, text.length());

		ClearOnSlash( second_parameter );
		result.emplace( std::make_pair( first_parameter, second_parameter ));
		return result;
	}

	void Parser::ClearOnSlash( std::string& parameter ) const
	{
		static const std::string SLASH_SIGN = "//";

		auto search_index = parameter.find( SLASH_SIGN );
		if( search_index == std::string::npos )
		{
			return;
		}
		parameter.erase( search_index );
		parameter.erase( std::remove_if( parameter.begin(), parameter.end(), ::isspace ), parameter.end() );
	}
}