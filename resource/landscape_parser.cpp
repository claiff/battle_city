//
// Created by claiff on 23.05.22.
//

#include "landscape_parser.hpp"

namespace resource
{
	LandscapeParser::LandscapeParser()
	{
		mLandscapeTable.insert( {"N", Id::Landscape::None} );

		mLandscapeTable.insert( {"B1", Id::Landscape::Brick_1} );
		mLandscapeTable.insert( {"B2", Id::Landscape::Brick_2} );
		mLandscapeTable.insert( {"B3", Id::Landscape::Brick_3} );
		mLandscapeTable.insert( {"B4", Id::Landscape::Brick_4} );
		mLandscapeTable.insert( {"B5", Id::Landscape::Brick_5} );

		mLandscapeTable.insert( {"I1", Id::Landscape::Iron_1} );
		mLandscapeTable.insert( {"I2", Id::Landscape::Iron_2} );
		mLandscapeTable.insert( {"I3", Id::Landscape::Iron_3} );
		mLandscapeTable.insert( {"I4", Id::Landscape::Iron_4} );
		mLandscapeTable.insert( {"I5", Id::Landscape::Iron_5} );
	}

	//TODO Объединить с parse.cpp
	std::list < Id::Landscape > LandscapeParser::Parse( const std::string& text ) const
	{
		std::list < Id::Landscape > result;
		std::stringstream ss( text );
		std::string item;
		char delim = ' ';

		while( getline( ss, item, delim ))
		{
			auto find = mLandscapeTable.find( item );
			if( find != mLandscapeTable.end())
			{
				result.push_back( find->second );
			}
		}

		return result;
	}


}