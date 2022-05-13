//
// Created by claiff on 27.04.22.
//


#pragma once

#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace resource
{
	enum class Id
	{
		Background,
		Border,
		Player
	};

	class Manager
	{
	public:
		explicit Manager( std::string const& texture_path );
		~Manager() = default;

		void Add( Id id, sf::IntRect const& rect_texture, sf::Vector2f const& scale = {1, 1} );
		[[nodiscard]] sf::Sprite Get( Id id ) const;
	private:
		std::shared_ptr < sf::Texture > mTexture;
		std::map < Id, sf::Sprite > mResource;
	};
}
