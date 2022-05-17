//
// Created by claiff on 16.05.22.
//

#pragma once

#include <memory>

namespace utils::types
{
	template<typename T>
	class Registrator
	{
	public:
		virtual ~Registrator() = default;

		virtual T& Get() = 0;
		virtual void Add( T const& element ) = 0;
	};

	template<typename T>
	using RegistratorPtr = std::shared_ptr < Registrator < T>>;
}