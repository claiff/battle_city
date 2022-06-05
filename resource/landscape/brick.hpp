//
// Created by claiff on 27.05.22.
//


#pragma once

#include "resource/types/ilandscape.hpp"

namespace resource::landscape
{
	class Brick : public types::ILandscape
	{
	public:
		Brick() = default;
		~Brick() override = default;
	};
} // landscape
