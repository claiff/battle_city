//
// Created by claif on 16.01.2022.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <mingw.mutex.h>

#include "types/ipicture_builder.hpp"
#include "layers/controller_full.hpp"

namespace picture
{
	class PictureBuilder
			: public types::IPictureBuilder
	{
	public:
		explicit PictureBuilder( layer::ControllersFull const& controllers );
		~PictureBuilder() override = default;

		void ReDraw() override;
	private:
		layer::ControllersFull const& mControllers;
		std::mutex mSpriteMutex;
	};
}

