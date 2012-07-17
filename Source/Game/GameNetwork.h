#ifndef __BLOCKWORLD_GAMENETWORK_H__
#define __BLOCKWORLD_GameNETWORK_H__

#include <enet/enet.h>

namespace BlockWorld {
	class GameObject;
	class GameNetwork {
		public:
			static const int MESSAGE_IDENTITY         = 1;
			static const int MESSAGE_CONNECT_RESPONSE = 2;
			static const int MESSAGE_JOIN             = 3;
			static const int MESSAGE_LEAVE            = 4;
			static const int MESSAGE_UPDATE           = 5;
			static const int MESSAGE_READY            = 6;
			static const int MESSAGE_LOAD_MAP         = 7;
			static const int MESSAGE_MAP_LOADED       = 8;
			static const int MESSAGE_START_GAME       = 9;
			static const int MESSAGE_SPAWN            = 10;
			static const int MESSAGE_SHOT             = 11;
			static const int MESSAGE_DEATH            = 12;
			static const int MESSAGE_END_GAME         = 13;
			
			static void sendUpdate(ENetHost* host, ENetPeer* peer, GameObject& object);
			
			GameNetwork();
			virtual ~GameNetwork();
	};
};

#endif // __BLOCKWORLD_GAMENETWORK_H__
