//
// Created by claiff on 16.05.22.
//


#pragma once

#include <vector>

#include "types/registrator.hpp"

namespace utils
{
	template<typename T>
	class ConsistentRegistrator
			: public types::Registrator < T >
	{
	public:
		ConsistentRegistrator()
				: mElementCounter{0}
		{

		}

		~ConsistentRegistrator() override = default;

		T& Get() override
		{
			if( mElementCounter == mElements.size())
			{
				mElementCounter = 0;
			}

			return mElements.at( mElementCounter++ );
		}

		void Add( T const& element ) override
		{
			mElements.push_back( element );
		}

	private:
		std::vector < T > mElements;
		std::size_t mElementCounter;
	};
}

