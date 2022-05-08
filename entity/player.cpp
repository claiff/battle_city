//
// Created by claiff on 08.05.22.
//

#include <SFML/include/SFML/Graphics/RenderTarget.hpp>

#include "player.hpp"

namespace entity
{

	Player::Player( sf::Sprite const& view )
			: mView( view )
	{
		mView.setPosition( {200, 200} );
	}

	void Player::Move( sf::Vector2f const& step )
	{
		auto position = mView.getPosition();
		position += step;
		mView.setPosition( position );
	}

	void Player::Fire()
	{

	}

	void Player::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		target.draw( mView );
	}

	sf::Vector2f Player::GetPosition() const
	{
		return mView.getPosition();
	}
}