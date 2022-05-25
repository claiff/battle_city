//
// Created by claiff on 19.05.22.
//


#pragma once

#include "resource/types/ibuilder.hpp"

namespace resource::builder
{
	class Landscape
			: public types::IBuilder < Id::Landscape >
	{
	public:
		Landscape() = default;
		~Landscape() override = default;

		Manager < Id::Landscape > Build() const override;
		void ApplyBricks( Manager < Id::Landscape >& result ) const;
		sf::Vector2i GetLandscapeSize() const;
		void ApplyIrons( Manager <Id::Landscape>& result ) const;
	};
}

