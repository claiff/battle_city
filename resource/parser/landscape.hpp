//
// Created by claiff on 23.05.22.
//


#pragma once

#include <list>

#include "resource/landscape/manager.hpp"
#include "resource/types/iparser.hpp"

namespace resource::parser
{
	using ParseResult = std::list < landscape::Id::Landscape >;
	using LandscapeTable = std::map < std::string, landscape::Id::Landscape >;

	class Landscape
			: public types::IParser < ParseResult >
	{
	public:
		Landscape();
		~Landscape() override = default;

		[[nodiscard]] ParseResult Parse( std::string const& text ) const override;
	private:
		void InsertBricks();
		void InsertIrons();

		LandscapeTable mLandscapes;
	};
}

