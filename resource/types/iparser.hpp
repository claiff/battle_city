//
// Created by claiff on 25.05.22.
//

#include <string>

namespace resource::types
{
	template<typename T>
	class IParser
	{
	public:
		virtual ~IParser() = default;

		virtual T Parse( std::string const& text ) const = 0;
	};
}