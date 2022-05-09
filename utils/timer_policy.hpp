//
// Created by claiff on 7/18/21.
//

#pragma once

#include <ctime>
#include <chrono>

#include "types/ipolicy.hpp"

namespace utils
{
	class TimerPolicy
			: public types::IPolicy
	{
	public:
		explicit TimerPolicy( int period_ms );
		~TimerPolicy() override = default;

		bool IsTime() const override;
	private:
		double mPeriod;
		mutable std::chrono::time_point < std::chrono::steady_clock > mTime;
	};
}



