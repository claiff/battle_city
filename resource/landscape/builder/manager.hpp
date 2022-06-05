//
// Created by claiff on 31.05.22.
//


#pragma once

#include "resource/landscape/manager.hpp"

namespace resource::landscape::builder
{
	class Manager
	{
	public:
		Manager() = default;
		~Manager() = default;

		resource::landscape::Manager Build() const;
	};
}
