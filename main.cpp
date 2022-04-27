#include "app/game.hpp"
#include "app/builder/window.hpp"
#include "app/keyboard_keys.hpp"

int main()
{
	auto window = app::builder::Window{}.Build();
	auto keys = std::make_shared < app::KeyboardKeys >( window );
	app::Game game{window, keys};
	game.Run();

	return 0;
}
