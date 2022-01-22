//
// Created by claif on 19.01.2022.
//

#pragma once

#include "layers/types/ilayer.hpp"

namespace layer::controller
{
	class Border
	{
	public:
		explicit Border(types::ILayerPtr const& layer);
		~Border() = default;
	};
}