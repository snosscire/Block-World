#include "Engine/SDL/SDLEngine.h"
#include "Game/Game.h"
#include "Game/BlockWorld.h"
#include "Game/NothingMode.h"
#include "Game/TestMode.h"
#include "Game/NetworkTestMode.h"
#include "Game/EndGameMode.h"
#include "Game/SplashMode.h"
#include "Game/ServerListMode.h"
#include "Game/ServerLobbyMode.h"

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
	//BlockWorld::EndGameMode* endGameMode = new BlockWorld::EndGameMode(game);
	//BlockWorld::SplashMode* splashMode = new BlockWorld::SplashMode(game);
	//BlockWorld::ServerListMode* serverListMode = new BlockWorld::ServerListMode(game);
	//BlockWorld::ServerLobbyMode* serverLobbyMode = new BlockWorld::ServerLobbyMode(game);
	
	game->registerMode(BlockWorld::NOTHING_MODE, nothingMode);
	game->registerMode(BlockWorld::TEST_MODE, testMode);
	game->registerMode(BlockWorld::NETWORK_TEST_MODE, networkTestMode);
	//game->registerMode(BlockWorld::END_GAME_MODE, endGameMode);
	//game->registerMode(BlockWorld::SPLASH_MODE, splashMode);
	//game->registerMode(BlockWorld::SERVER_LIST_MODE, serverListMode);
	//game->registerMode(BlockWorld::SERVER_LOBBY_MODE, serverLobbyMode);
	
	game->run(BlockWorld::NETWORK_TEST_MODE);
	
	delete nothingMode;
	delete testMode;
	delete networkTestMode;
	//delete endGameMode;
	//delete splashMode;
	//delete serverListMode;
	//delete serverLobbyMode;
	delete game;
	delete engine;
	
	enet_deinitialize();
	
	return 0;
}
