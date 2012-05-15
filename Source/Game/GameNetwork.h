#ifndef __BLOCKWORLD_GAMENETWORK_H__
#define __BLOCKWORLD_GameNETWORK_H__

#include <enet/enet.h>

namespace BlockWorld {
	class GameObject;
	class GameNetwork {
		public:
			static const int MESSAGE_CONNECT          = 1;
			static const int MESSAGE_CONNECT_RESPONSE = 2;
			static const int MESSAGE_JOIN             = 3;
			static const int MESSAGE_LEAVE            = 4;
			static const int MESSAGE_UPDATE           = 5;
			
			static void sendUpdate(ENetHost* host, ENetPeer* peer, GameObject& object);
			
			GameNetwork();
			virtual ~GameNetwork();
	};
};

#endif // __BLOCKWORLD_GAMENETWORK_H__