//
// Created by claif on 16.01.2022.
//

#pragma once

#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace layer::types
{
	class ILayer
	{
	public:
		ILayer()
		{
			if( !mRenderTexture.create( 800, 600 ))
			{
				throw "IDecorator::IDecorator Невозможно отрисовать mRenderTexture";
			}
		}

		virtual ~ILayer() = default;

		virtual sf::Sprite GetSprite() = 0;
	protected:
		sf::RenderTexture mRenderTexture;
	};

	using ILayerPtr = std::shared_ptr < ILayer >;
}