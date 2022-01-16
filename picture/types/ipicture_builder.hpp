//
// Created by claif on 16.01.2022.
//

#pragma once

#include <memory>

namespace picture::types
{
	class IPictureBuilder
	{
	public:
		virtual ~IPictureBuilder() = default;

		virtual void ReDraw() = 0;
	};
	using IPictureBuilderPtr = std::shared_ptr<IPictureBuilder>;
}

