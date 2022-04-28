//
// Created by claiff on 27.04.22.
//


#pragma once

#include <map>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace resource
{
	enum class Id
	{
		Background,
		Border
	};

	class Manager
	{
	public:
		explicit Manager( sf::Texture const& texture );
		~Manager() = default;

		void Add( Id id, sf::Rect < int > const& rect_texture );
		sf::Sprite& Get( Id id );
	private:
		sf::Texture mTexture;
		std::map < Id, sf::Sprite > mResource;
	};
}
