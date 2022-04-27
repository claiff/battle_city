//
// Created by claiff on 27.04.22.
//

#pragma once

#include <memory>

namespace app::types
{
	enum class Keys
			: int
	{
		None = 0x00,
		PushUp = 1 << 0,
		RealizeUp = 1 << 1,
		PushDown = 1 << 2,
		RealizeDown = 1 << 3,
		PushLeft = 1 << 4,
		RealizeLeft = 1 << 5,
		PushRight = 1 << 6,
		RealizeRight = 1 << 7,
		PushUse = 1 << 8,
		RealizeUse = 1 << 9,
	};

	class IKeys
	{
	public:
		virtual ~IKeys() = default;

		virtual Keys Get() = 0;
	};

	using KeysPtr = std::shared_ptr < IKeys >;
}