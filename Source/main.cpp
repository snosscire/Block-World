#include "Engine/SDL/SDLEngine.h"
#include "Engine/Game.h"
#include "Game/BlockWorld.h"
#include "Game/TestMode.h"

int main(int argc, char *argv[])
{
	BadEngine::Engine* engine = new BadEngine::SDLEngine();
	BadEngine::Game* game = new BadEngine::Game(engine);
	BlockWorld::TestMode* testMode = new BlockWorld::TestMode(game);
	
	game->registerMode(BlockWorld::TEST_MODE, testMode);
	game->run(BlockWorld::TEST_MODE);
	
	delete testMode;
	delete game;
	delete engine;
	
	return 0;
}
