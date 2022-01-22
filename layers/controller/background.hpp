//
// Created by claif on 19.01.2022.
//

#pragma once

#include "layers/types/ilayer.hpp"

namespace layer::controller
{
	class Background
	{
	public:
		explicit Background( types::ILayerPtr const& layer );
		~Background() = default;
	};
}

