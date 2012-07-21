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
	class NetworkMessage;
	class IdentityMessage;
	class ReadyMessage;
	class MapLoadedMessage;
	class SpawnMessage;
	class UpdateMessage;
	class ShotMessage;
	class DeathMessage;
	class GameNetworkServer : public NetworkServer, public NetworkObserver {
		private:
			bool m_gameInProgress;
			int m_lastClientID;
			map<int, ServerClient*> m_clients;
		
		private:
			void sendToAll(unsigned char* data, unsigned int length);
			void sendToAll(string& data);
			void sendToAll(NetworkMessage& message);
			void sendToAllExcept(unsigned char* data, unsigned int length, int clientID);
			void sendToAllExcept(string& data, int clientID);
			void sendToAllExcept(NetworkMessage& message, int clientID);
			ServerClient* getClient(int id);
			void handleIdentityMessage(IdentityMessage& message);
			void handleReadyMessage(ReadyMessage& message);
			void handleMapLoadedMessage(MapLoadedMessage& message);
			void handleUpdateMessage(UpdateMessage& updateMessage, ENetPacket* packet);
			void handleSpawnMessage(SpawnMessage& updateMessage, ENetPacket* packet);
			void handleShotMessage(ShotMessage& message, ENetPacket* packet);
			void handleDeathMessage(DeathMessage& message, ENetPacket* packet);
			int playersAlive();
			string findWinner();
			void sendEndGameMessage();
		
		public:
			GameNetworkServer();
			virtual ~GameNetworkServer();
			void onConnect(ENetPeer* peer);
			void onDisconnect(ENetPeer* peer);
			void onReceive(ENetPacket* packet);
	};
};

#endif
