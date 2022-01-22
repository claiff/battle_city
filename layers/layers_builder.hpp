//
// Created by claif on 19.01.2022.
//

#pragma once

#include "types/ilayer.hpp"
#include "controller_full.hpp"

namespace layer
{
	class LayersBuilder
	{
	public:
		LayersBuilder() = default;
		~LayersBuilder() = default;

		types::ILayerPtr MakeLayersDecorators();
		ControllersFull MakeControllersClass();

	private:
		ControllersFull mControllersFull;
	};
}

