//
// Created by claiff on 16.05.22.
//


#pragma once

#include <vector>

#include "types/registrator.hpp"

namespace utils
{
	template<typename T>
	class ContinueRegistrator
			: public types::Registrator < T >
	{
	public:
		ContinueRegistrator()
				: mElementCounter{0}
		{

		}

		~ContinueRegistrator() override = default;

		T& Get() override
		{
			if( mElementCounter != mElements.size())
			{
				++mElementCounter;
			}

			return mElements.at( mElementCounter );
		}

		void Add( T const& element ) override
		{
			mElements.push_back( element );
		}

		void ResetCount() override
		{
			mElementCounter = 0;
		}


	private:
		std::vector < T > mElements;
		mutable std::size_t mElementCounter;
	};
}

