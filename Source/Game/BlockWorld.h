#ifndef __BLOCKWORLD_H__
#define __BLOCKWORLD_H__

#include <string>

using namespace std;

namespace BlockWorld {
	const string NOTHING_MODE = "Nothing";
	const string TEST_MODE = "Test";
	const string NETWORK_TEST_MODE = "NetworkTest";
	const string END_GAME_MODE = "EndGame";
	const string SPLASH_MODE = "Splash";
	const string SERVER_LIST_MODE = "ServerList";
	const string SERVER_LOBBY_MODE = "ServerLobby";
	const int BLOCK_WIDTH = 16;
	const int BLOCK_HEIGHT = 16;
	const double DEFAULT_GRAVITY = 4.0;
	const double MAX_CROSSHAIR_DISTANCE = 180.0;
};

#endif // __BLOCKWORLD_H__
