#include "Engine/SDL/SDLEngine.h"
#include "Game/Game.h"
#include "Game/BlockWorld.h"
#include "Game/NothingMode.h"
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
	
	BlockWorld::NothingMode* nothingMode = new BlockWorld::NothingMode(game);
	BlockWorld::TestMode* testMode = new BlockWorld::TestMode(game);
	BlockWorld::NetworkTestMode* networkTestMode = new BlockWorld::NetworkTestMode(game);
	
	game->registerMode(BlockWorld::NOTHING_MODE, nothingMode);
	game->registerMode(BlockWorld::TEST_MODE, testMode);
	game->registerMode(BlockWorld::NETWORK_TEST_MODE, networkTestMode);
	
	game->run(BlockWorld::NETWORK_TEST_MODE);
	
	delete nothingMode;
	delete testMode;
	delete networkTestMode;
	delete game;
	delete engine;
	
	enet_deinitialize();
	
	return 0;
}
