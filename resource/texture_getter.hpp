//
// Created by claiff on 19.05.22.
//


#pragma once

#include <SFML/Graphics/Texture.hpp>

namespace resource
{
	class TextureGetter
	{
	public:
		TextureGetter() = delete;
		~TextureGetter() = default;

		static sf::Texture& Get();
	private:
		static void CreateTexture();

		static std::shared_ptr < sf::Texture > mTexture;
	};
} // resource
