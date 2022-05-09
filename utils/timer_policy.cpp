//
// Created by claiff on 7/18/21.
//

#include "timer_policy.hpp"

namespace utils
{
	TimerPolicy::TimerPolicy( int period_ms )
			:
			mPeriod( static_cast<double >(period_ms) / 1000 )
			, mTime( std::chrono::steady_clock::now())
	{
	}

	bool TimerPolicy::IsTime() const
	{
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration < double > elapsed_seconds = now - mTime;
		if( elapsed_seconds.count() > mPeriod )
		{
			mTime = now;
			return true;
		}
		return false;
	}

}
