//
// Created by claif on 08.01.2022.
//

#pragma once

#include <memory>

namespace main_program::types
{
	class IWindow
	{
	public:
		virtual ~IWindow() = default;

		virtual void ReDraw() const = 0;
	};

	using IWindowPtr = std::shared_ptr < IWindow >;
}

