//
// Created by claif on 19.01.2022.
//

#include "layers_builder.hpp"
#include "layers/decorators/background.hpp"
#include "layers/decorators/border_decorator.hpp"

#include "layers/controller/background.hpp"
#include "layers/controller/border.hpp"

namespace layer
{
	types::ILayerPtr LayersBuilder::MakeLayersDecorators()
	{
		auto background = std::make_shared < Background >();
		mControllersFull.mBackgroundController = controller::Background( background );
		auto border = std::make_shared < Border >( background );
		mControllersFull.mBorderController = controller::Border( border );
		return border;
	}

	ControllersFull LayersBuilder::MakeControllersClass()
	{
		return mControllersFull;
	}
}