//
// Created by claiff on 27.04.22.
//


#pragma once

#include "resource/types/ibuilder.hpp"

namespace resource::builder
{
	class AllyTank
			: public types::IBuilder < Id::AllyTank >
	{
	public:
		AllyTank() = default;
		~AllyTank() override = default;

		[[nodiscard]] Manager < Id::AllyTank > Build() const override;
	private:
		sf::Rect < int > mWindow_rect;
	};
}

