//
// Created by claif on 08.01.2022.
//

#include "window.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/System/String.hpp>

namespace main_program
{
	Window::Window( sf::Rect < unsigned int > const& rect, sf::String const& title, sf::Sprite const& drawing_sprite )
			: mDrawingSprite( drawing_sprite )
	{
		//FIXME
//		mWindow.setSize( {rect.width, rect.height} );
//		sf::Vector2i position = {static_cast<int>(rect.left), static_cast<int>(rect.top)};
//		mWindow.setPosition( position );
//		mWindow.setTitle( title );
		mWindow = new sf::RenderWindow{sf::VideoMode( 800, 600 ), "My window"};
		mWindow->setFramerateLimit( 60 );
	}

	void Window::ReDraw() const
	{
		while( mWindow->isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event{};
			while( mWindow->pollEvent( event ))
			{
				// "close requested" event: we close the window
				if( event.type == sf::Event::Closed )
				{
					mWindow->close();
				}
			}

			// clear the window with black color
			mWindow->clear( sf::Color::Black );
			mWindow->draw( mDrawingSprite );
			mWindow->display();
		}
	}

	Window::~Window()
	{
		delete mWindow;
	}
}