//
// Created by claiff on 23.05.22.
//

#include "landscape.hpp"

namespace resource::parser
{
	//
	//Constructors
	//

	Landscape::Landscape()
	{
		mLandscapes.insert( {"N", Id::Landscape::None} );
		mLandscapes.insert( {"F", Id::Landscape::Flag_1} );

		InsertBricks();
		InsertIrons();
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

	void Landscape::InsertBricks()
	{
		mLandscapes.insert( {"B1", Id::Landscape::Brick_1} );
		mLandscapes.insert( {"B2", Id::Landscape::Brick_2} );
		mLandscapes.insert( {"B3", Id::Landscape::Brick_3} );
		mLandscapes.insert( {"B4", Id::Landscape::Brick_4} );
		mLandscapes.insert( {"B5", Id::Landscape::Brick_5} );
		mLandscapes.insert( {"B6", Id::Landscape::Brick_6} );
		mLandscapes.insert( {"B7", Id::Landscape::Brick_7} );
	}

	void Landscape::InsertIrons()
	{
		mLandscapes.insert( {"I1", Id::Landscape::Iron_1} );
		mLandscapes.insert( {"I2", Id::Landscape::Iron_2} );
		mLandscapes.insert( {"I3", Id::Landscape::Iron_3} );
		mLandscapes.insert( {"I4", Id::Landscape::Iron_4} );
		mLandscapes.insert( {"I5", Id::Landscape::Iron_5} );
	}
}