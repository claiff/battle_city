//
// Created by claiff on 27.04.22.
//

#include "background.hpp"

namespace layer
{

	Background::Background( resource::Manager const& sprite_manager )
			: mSpriteManager( sprite_manager )
	{

	}

	void Background::Draw()
	{
		auto sprite = mSpriteManager.Get( resource::Id::Background );

	}
}