//
// Created by claif on 16.01.2022.
//

#pragma once

#include <string>
#include <unordered_map>

#include "parser.hpp"

namespace resource::ini
{
	using ParametersSet = std::unordered_map < std::string, std::string >;

	class IniReader
	{
	public:
		IniReader( Parser const& parser, std::string const& path );
		~IniReader() = default;

		std::string GetValue( std::string const& parameter ) const noexcept;
	private:
		void ProcessLine( Parser const& parser, const std::string& line );

		ParametersSet mParameters;
	};
}