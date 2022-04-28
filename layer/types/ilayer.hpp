//
// Created by claiff on 27.04.22.
//

#pragma once

namespace layer::types
{
	class ILayer
	{
	public:
		virtual ~ILayer() = 0;

		virtual void Draw() = 0;
	};
}