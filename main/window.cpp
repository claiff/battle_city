//
// Created by claif on 08.01.2022.
//

#include "window.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/System/String.hpp>
#include "resource/ini/ini_reader.hpp"

namespace main_program
{
	Window::Window(
			layer::types::ILayerPtr const& layers )
			: mLayers( layers )
	{
		auto width = std::stoi( resource::ini::IniReader::GetValue( "default_window_width" ));
		auto height = std::stoi( resource::ini::IniReader::GetValue( "default_window_height" ));
		//FIXME
		mWindow = new sf::RenderWindow{sf::VideoMode( width, height ), "My window"};
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
			mWindow->clear( sf::Color::Red );
			DrawSprite();
			mWindow->display();
		}
	}

	void Window::DrawSprite() const
	{
		std::lock_guard < std::mutex > lock{mDrawSpriteMutex};
		auto sprite = mLayers->GetSprite();
		mWindow->draw( sprite );
	}

	Window::~Window()
	{
		delete mWindow;
	}
}