#include "Engine/SDL/SDLEngine.h"
#include "Game/Game.h"
#include "Game/BlockWorld.h"
#include "Game/TestMode.h"
#include "Game/NetworkTestMode.h"

#include "External/aphex/aphex.h"

#include <enet/enet.h>

int main(int argc, char *argv[])
{
	aphex_init(0);
	enet_initialize();
	
	BadEngine::Engine* engine = new BadEngine::SDLEngine();
	BlockWorld::Game* game = new BlockWorld::Game(engine);
	//BlockWorld::TestMode* testMode = new BlockWorld::TestMode(game);
	BlockWorld::NetworkTestMode* testMode = new BlockWorld::NetworkTestMode(game);
	
	game->registerMode(BlockWorld::NETWORK_TEST_MODE, testMode);
	game->run(BlockWorld::NETWORK_TEST_MODE);
	
	delete testMode;
	delete game;
	delete engine;
	
	enet_deinitialize();
	
	return 0;
}
