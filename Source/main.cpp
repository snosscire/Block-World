#include "Engine/SDL/SDLEngine.h"
#include "Game/Game.h"
#include "Game/BlockWorld.h"
#include "Game/TestMode.h"

#include "External/aphex/aphex.h"

int main(int argc, char *argv[])
{
	aphex_init(0);
	
	BadEngine::Engine* engine = new BadEngine::SDLEngine();
	BlockWorld::Game* game = new BlockWorld::Game(engine);
	BlockWorld::TestMode* testMode = new BlockWorld::TestMode(game);
	
	game->registerMode(BlockWorld::TEST_MODE, testMode);
	game->run(BlockWorld::TEST_MODE);
	
	delete testMode;
	delete game;
	delete engine;
	
	return 0;
}
