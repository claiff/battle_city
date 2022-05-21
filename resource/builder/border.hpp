//
// Created by claiff on 19.05.22.
//


#pragma once

#include "types/ibuilder.hpp"

namespace resource::builder
{
	class Border
			: public types::IBuilder < Id::Border >
	{
	public:
		Border() = default;
		~Border() override = default;

		Manager < Id::Border > Build() const override;
	};
}
