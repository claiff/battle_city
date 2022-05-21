//
// Created by claiff on 17.05.22.
//

#pragma once

#include "ientity.hpp"

namespace entity::types
{

	class ITankEntity
			: public IEntity
	{
	public:
		~ITankEntity() override = default;

		virtual void Fire() = 0;
		virtual void StartMove( Direction direction ) = 0;
		virtual void StopMove( Direction direction ) = 0;
		virtual void Upgrade() = 0;
	};

	using ITankEntityPtr = std::shared_ptr < ITankEntity >;
}