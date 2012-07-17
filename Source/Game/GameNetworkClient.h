#ifndef __BLOCKWORLD_GAMENETWORKCLIENT_H__
#define __BLOCKWORLD_GAMENETWORKCLIENT_H__

#include "../Engine/NetworkClient.h"
#include "../Engine/NetworkObserver.h"

#include <list>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class NetworkMessage;
	class MessageObserver;
	class GameObject;
	class GameNetworkClient : public NetworkClient, public NetworkObserver {
		private:
			list<MessageObserver*> m_messageObservers;
		public:
			GameNetworkClient();
			virtual ~GameNetworkClient();
			void registerMessageObserver(MessageObserver* observer);
			void unregisterObserver(MessageObserver* observer);
			void sendMessage(NetworkMessage& message);
			void sendUpdate(GameObject& object);
			void sendUpdate(GameObject& object, bool moveLeft, bool moveRight, bool jump);
			void onReceive(ENetPacket* packet);
	};
};

#endif
