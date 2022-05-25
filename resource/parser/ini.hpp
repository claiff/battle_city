//
// Created by claif on 16.01.2022.
//

#pragma once

#include <optional>
#include <string>

#include "resource/types/iparser.hpp"

namespace resource::parser
{
	using ParseResult = std::optional < std::pair < std::string, std::string > >;

	class Ini
			: public types::IParser < ParseResult >
	{
	public:
		Ini() = default;
		~Ini() override = default;

		[[nodiscard]] ParseResult Parse( std::string const& text ) const override;
	private:
		void ClearOnSlash( std::string& parameter ) const;
	};
}