//
// Created by claiff on 27.04.22.
//


#pragma once

#include "types/ilayer.hpp"
#include "resource/manager.hpp"

namespace layer
{
	class Background
			: public types::ILayer
	{
	public:
		explicit Background( resource::Manager const& sprite_manager );
		~Background() override = default;
		virtual void Draw() override;
	private:
		resource::Manager  mSpriteManager;
	};

}
