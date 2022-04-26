#include "app/game.hpp"
#include "app/builder/window.hpp"

int main()
{
	auto window = app::builder::Window{}.Build();
	app::Game game{window};
	game.Run();

	return 0;
}
