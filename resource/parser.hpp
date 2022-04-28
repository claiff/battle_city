//
// Created by claif on 16.01.2022.
//

#pragma once

#include <optional>
#include <string>

namespace resource
{
	using ParseResult = std::optional < std::pair < std::string, std::string > >;

	class Parser
	{
	public:
		Parser() = default;
		~Parser() = default;

		ParseResult Parse( std::string const& text ) const;
	private:
		void ClearOnSlash( std::string& parameter ) const;
	};
}