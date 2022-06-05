//
// Created by claiff on 23.05.22.
//

#include <sstream>

#include "landscape.hpp"

namespace resource::parser
{
	//
	//Constructors
	//

	Landscape::Landscape()
	{
		mLandscapes.insert( {"N", landscape::Id::Landscape::None} );
		mLandscapes.insert( {"B", landscape::Id::Landscape::Brick} );
		mLandscapes.insert( {"Ir", landscape::Id::Landscape::Iron} );
		mLandscapes.insert( {"F", landscape::Id::Landscape::Flag} );

		//InsertBricks();
		//InsertIrons();
	}

	//
	//Public methods
	//

	ParseResult Landscape::Parse( const std::string& text ) const
	{
		static constexpr char DELIMITER = ' ';

		ParseResult result;
		std::stringstream stream{text};
		std::string splitted_data;

		while( getline( stream, splitted_data, DELIMITER ))
		{
			auto find = mLandscapes.find( splitted_data );
			if( find != mLandscapes.end())
			{
				result.push_back( find->second );
			}
		}
		return result;
	}

	//
	//Private methods
	//

}