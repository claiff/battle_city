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
		explicit Manager( std::string const& texture_path );
		~Manager() = default;

		void Add( Id id, sf::Rect < int > const& rect_texture, sf::Vector2f const& scale );
		sf::Sprite Get( Id id ) const;
	private:
		std::shared_ptr < sf::Texture > mTexture;
		std::map < Id, sf::Sprite > mResource;
	};
}
