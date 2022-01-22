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
		mControllersFull.mBackgroundController = controller::Background();
		mControllersFull.mBorderController = controller::Border();
		auto background = std::make_shared < Background >( mControllersFull.mBackgroundController);
		return std::make_shared < Border >( background,mControllersFull.mBorderController  );
	}

	ControllersFull LayersBuilder::MakeControllersClass()
	{
		return mControllersFull;
	}
}