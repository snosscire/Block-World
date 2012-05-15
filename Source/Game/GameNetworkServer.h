#ifndef __BLOCKWORLD_GAMENETWORKSERVER_H__
#define __BLOCKWORLD_GAMENETWORKSERVER_H__

#include "../Engine/NetworkServer.h"
#include "../Engine/NetworkObserver.h"

#include <map>
#include <string>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class ServerClient;
	class ConnectMessage;
	class UpdateMessage;
	class GameNetworkServer : public NetworkServer, public NetworkObserver {
		private:
			int m_lastClientID;
			map<int, ServerClient*> m_clients;
		
		private:
			void sendToAll(unsigned char* data, unsigned int length);
			void sendToAll(string& data);
			void sendToAllExcept(unsigned char* data, unsigned int length, int clientID);
			void sendToAllExcept(string& data, int clientID);
			
			void handleConnectMessage(ConnectMessage& message);
			void handleUpdateMessage(UpdateMessage& updateMessage, ENetPacket* packet);
		
		public:
			GameNetworkServer();
			virtual ~GameNetworkServer();
			void onConnect(ENetPeer* peer);
			void onDisconnect(ENetPeer* peer);
			void onReceive(ENetPacket* packet);
	};
};

#endif
