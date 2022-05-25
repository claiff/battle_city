//
// Created by claif on 16.01.2022.
//

#pragma once

#include <string>
#include <unordered_map>

namespace resource::reader
{
	using ParametersSet = std::unordered_map < std::string, std::string >;

	class Ini
	{
	public:
		~Ini() = default;

		static std::string GetValue( std::string const& parameter ) noexcept;
	private:
		static void InitReader();
		static void ProcessLine(  std::string const& line );

		static ParametersSet mParameters;
		static bool mIsInit;
	};
}