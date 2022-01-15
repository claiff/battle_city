//
// Created by claif on 08.01.2022.
//

#pragma once

#include <memory>

namespace main_program::types
{
	class IGame
	{
	public:
		virtual ~IGame() = default;

		virtual void Play() = 0;
	};

	using IGamePtr = std::shared_ptr < IGame >;
}

