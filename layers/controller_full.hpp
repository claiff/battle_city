//
// Created by claif on 19.01.2022.
//

#pragma once

#include "layers/controller/border.hpp"
#include "layers/controller/background.hpp"

namespace layer
{
	class ControllersFull
	{
	public:
		ControllersFull() = default;
		~ControllersFull() = default;

		controller::Background mBackgroundController;
		controller::Border mBorderController;
	};
}

