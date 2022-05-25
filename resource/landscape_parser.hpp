//
// Created by claiff on 23.05.22.
//


#pragma once

#include <list>

#include "resource/manager.hpp"

namespace resource
{
	class LandscapeParser
	{
	public:
		LandscapeParser();
		~LandscapeParser() = default;

		std::list < Id::Landscape > Parse( std::string const& text ) const;
	private:
		std::map < std::string, Id::Landscape > mLandscapeTable;
	};
}

