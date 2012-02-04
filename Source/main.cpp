#include "Engine/SDL/SDLEngine.h"
#include "Game.h"
#include "BlockWorld.h"
#include "TestMode.h"

int main(int argc, char *argv[])
{
	BadEngine::Engine* engine = new BadEngine::SDLEngine();
	Game* game = new Game(engine);
	TestMode* testMode = new TestMode(game);
	
	game->registerMode(BlockWorld::TEST_MODE, testMode);
	game->run(BlockWorld::TEST_MODE);
	
	delete testMode;
	delete game;
	delete engine;
	
	return 0;
}
