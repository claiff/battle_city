//
// Created by claiff on 27.04.22.
//


#pragma once

#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace resource
{
	namespace Id
	{
		enum class AllyTank
		{
			NormalYellow_1,
			NormalYellow_2,
			LightYellow_1,
			LightYellow_2,
			MediumYellow_1,
			MediumYellow_2,
			HeavyYellow_1,
			HeavyYellow_2,
			Projectile
		};

		enum class Border
		{
			Background,

		};

		enum class Landscape
		{
			None
		};
	}
	template<class T>
	class Manager
	{
	public:
		explicit Manager( sf::Texture const& texture )
				: mTexture( texture )
		{

		}

		~Manager() = default;

		void Add( T id, sf::IntRect const& rect_texture, sf::Vector2f const& scale = {1, 1} )
		{
			sf::Sprite sprite;
			sprite.setTexture( mTexture );
			sprite.setTextureRect( rect_texture );
			sprite.setScale( scale );
			auto result = mResource.insert( std::make_pair( id, std::move( sprite )));
			assert( result.second );
		}

		[[nodiscard]] sf::Sprite const& Get( T id ) const
		{
			auto find = mResource.find( id );
			if( find == mResource.end())
			{
				find = mResource.find( id );
			}
			assert( find != mResource.end());
			return find->second;

		}

	private:
		sf::Texture const& mTexture;
		std::map < T, sf::Sprite > mResource;
	};
}
