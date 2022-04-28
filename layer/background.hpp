//
// Created by claiff on 27.04.22.
//


#pragma once

#include "types/ilayer.hpp"

namespace layer
{
	class Background
			: public types::ILayer
	{
	public:
		Background();
		~Background() override = default;
	};

}
