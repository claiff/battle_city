//
// Created by claiff on 27.04.22.
//

#include <SFML/Window/Event.hpp>

#include "keyboard_keys.hpp"

namespace app
{
	KeyboardKeys::KeyboardKeys( std::shared_ptr < sf::RenderWindow > const& window )
			: mWindow( window )
	{

	}

	types::Keys KeyboardKeys::Get()
	{
		sf::Event event{};
		auto result = types::Keys::None;
		while( mWindow->pollEvent( event ))
		{
			switch( event.key.code )
			{
				case sf::Keyboard::W :
					//TODO Поправить этот бред
					AddResult( result, IsKeyPressed( event ) ? types::Keys::PushUp : types::Keys::RealizeUp );
					break;
				case sf::Keyboard::S :
					AddResult( result, IsKeyPressed( event ) ? types::Keys::PushDown : types::Keys::RealizeDown );
					break;
				case sf::Keyboard::D :
					AddResult( result, IsKeyPressed( event ) ? types::Keys::PushRight : types::Keys::RealizeRight );
					break;
				case sf::Keyboard::A :
					AddResult( result, IsKeyPressed( event ) ? types::Keys::PushLeft : types::Keys::RealizeLeft );
					break;
				case sf::Keyboard::Space :
					AddResult( result, IsKeyPressed( event ) ? types::Keys::PushUse : types::Keys::RealizeUse );
					break;
				default:
					if( event.type == sf::Event::Closed )
					{
						mWindow->close();
					}
					break;

			}


		}
		return result;
	}

	bool KeyboardKeys::IsKeyPressed( sf::Event const& event ) const noexcept
	{
		return event.type == sf::Event::KeyPressed;
	}

	void KeyboardKeys::AddResult( types::Keys& result, types::Keys operand )
	{
		auto temp = static_cast<int>(result) | static_cast<int>(operand);
		result = static_cast<types::Keys>(temp);
	}

}