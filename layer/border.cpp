//
// Created by claiff on 08.05.22.
//

#include "border.hpp"
#include "resource/reader/ini.hpp"
#include "resource/texture_getter.hpp"

namespace layer
{
	static const sf::Vector2f ZERO_POSITION = {0, 0};
	static const unsigned int COUNT_RIGHT_BORDER = 2;
	static const float COUNT_BOTTOM_BORDER = 0.5;
	static const unsigned int COUNT_LEFT_BORDER = 1;
	static const float COUNT_TOP_BORDER = 0.5;
	//
	//Constructors
	//

	Border::Border( resource::Manager<resource::Id::Border> const& sprite_manager )
	{
		const auto& sprite = sprite_manager.Get( resource::Id::Border::Background );

		ApplyBorderUp( sprite );
		ApplyBorderDown( sprite );
		ApplyBorderLeft( sprite );
		ApplyBorderRight( sprite );
	}

	//
	//Public methods
	//

	sf::FloatRect Border::GetGameRect() const
	{
		sf::FloatRect result;
		result.top = mUp.getSize().y;
		result.left = mLeft.getSize().x;
		result.width = GetWindowSize().x - result.left - mRight.getSize().x;
		result.height = GetWindowSize().y - result.top - mDown.getSize().y;
		return result;
	}

	void Border::draw( sf::RenderTarget& target, sf::RenderStates const& states ) const
	{
		if( mBase )
		{
			mBase->draw( target, states );
		}
		target.draw( mUp );
		target.draw( mRight );
		target.draw( mDown );
		target.draw( mLeft );
	}

	types::CollisionsSet Border::GetCollisions( sf::FloatRect const& rect )
	{
		types::CollisionsSet result;
		if( mBase )
		{
			result = mBase->GetCollisions( rect );
		}
		if( GetIntersection( mUp, rect ) ||
			GetIntersection( mRight, rect ) ||
			GetIntersection( mDown, rect ) ||
			GetIntersection( mLeft, rect ))
		{
			result.push_back( this );
		}

		return result;
	}

	//
	//Private methods
	//
	void Border::ApplyBorderUp( sf::Sprite const& sprite )
	{
		mUp.setPosition( ZERO_POSITION );
		mUp.setSize( GetSizeUpBorder( sprite ));
		ApplyTexture( mUp, sprite );
	}

	sf::Vector2f Border::GetSizeUpBorder( const sf::Sprite& sprite ) const
	{
		auto window_size = GetWindowSize();
		auto y = COUNT_TOP_BORDER * sprite.getTextureRect().height * sprite.getScale().y;
		return {window_size.x, y};
	}

	void Border::ApplyBorderRight( sf::Sprite const& sprite )
	{
		//TODO выпилить
		auto position = GetPositionRightBorder( sprite );
		auto size = GetSizeRightBorder( position, sprite );

		mRight.setPosition( position );
		mRight.setSize( size );
		ApplyTexture( mRight, sprite );
	}

	sf::Vector2f Border::GetPositionRightBorder( sf::Sprite const& sprite ) const
	{
		static constexpr int ZERO_POSITION_Y = 0;

		auto window_size = GetWindowSize();
		auto init_scale = sprite.getScale();
		float x = window_size.x - COUNT_RIGHT_BORDER * sprite.getTextureRect().width * init_scale.x;
		return {x, ZERO_POSITION_Y};
	}

	sf::Vector2f Border::GetSizeRightBorder( sf::Vector2f const& position, sf::Sprite const& sprite ) const
	{
		auto window_size = GetWindowSize();
		auto x = window_size.x - position.x;
		return {x, window_size.y};
	}

	void Border::ApplyBorderDown( sf::Sprite const& sprite )
	{
		auto position = GetPositionDownBorder( sprite );
		auto size = GetSizeDownBorder( position, sprite );

		mDown.setPosition( position );
		mDown.setSize( size );
		ApplyTexture( mDown, sprite );
	}

	sf::Vector2f Border::GetPositionDownBorder( sf::Sprite const& sprite ) const
	{
		static constexpr int ZERO_POSITION_X = 0;

		auto window_size = GetWindowSize();
		auto init_scale = sprite.getScale();
		float y = window_size.y - COUNT_BOTTOM_BORDER * sprite.getTextureRect().height * init_scale.y;
		return {ZERO_POSITION_X, y};
	}

	sf::Vector2f Border::GetSizeDownBorder( const sf::Vector2f& position, const sf::Sprite& sprite ) const
	{
		auto window_size = GetWindowSize();
		auto y = window_size.y - position.y;
		return {window_size.x, y};
	}

	void Border::ApplyBorderLeft( sf::Sprite const& sprite )
	{
		mLeft.setPosition( ZERO_POSITION );
		mLeft.setSize( GetSizeLeftBorder( sprite ));
		ApplyTexture( mLeft, sprite );
	}

	sf::Vector2f Border::GetSizeLeftBorder( sf::Sprite const& sprite ) const
	{
		auto window_size = GetWindowSize();
		auto x = COUNT_LEFT_BORDER * sprite.getTextureRect().width * sprite.getScale().x;
		return {x, window_size.y};
	}

	void Border::ApplyTexture( sf::RectangleShape& rect_shape, const sf::Sprite& sprite )
	{
		rect_shape.setTexture( sprite.getTexture());
		rect_shape.setTextureRect( sprite.getTextureRect());
	}

	sf::Vector2f Border::GetWindowSize() const
	{
		auto window_width = std::stof( resource::reader::Ini::GetValue( "default_window_width" ));
		auto window_height = std::stof( resource::reader::Ini::GetValue( "default_window_height" ));
		return {window_width, window_height};
	}

	bool Border::GetIntersection( sf::RectangleShape const& border, sf::FloatRect const& rect ) const
	{
		auto bounds = border.getGlobalBounds();
		return bounds.findIntersection( rect ) ? true : false;
	}
}