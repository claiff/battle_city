//
// Created by claiff on 7/18/21.
//

#pragma once

#include <memory>

namespace utils::types
{
	class IPolicy
	{
	public:
		virtual ~IPolicy() = default;

		[[nodiscard]] virtual bool IsTime() const = 0;
		virtual void SetPeriod( unsigned int period_ms ) = 0;
	};

	using IPolicyPtr = std::shared_ptr < IPolicy >;
}
