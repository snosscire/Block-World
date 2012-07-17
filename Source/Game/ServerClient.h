#ifndef __BLOCKWORLD_SERVERCLIENT_H__
#define __BLOCKWORLD_SERVERCLIENT_H__

#include <enet/enet.h>

#include <string>

using namespace std;

namespace BlockWorld {
	class GameObject;
	class NetworkMessage;
	class ServerClient {
		private:
			int m_id;
			ENetPeer* m_peer;
			double m_x;
			double m_y;
			string m_name;
			bool m_ready;
			bool m_mapLoaded;
			int m_lives;
		
		private:
			ServerClient();
		
		public:
			ServerClient(int id, ENetPeer* peer);
			virtual ~ServerClient();
			int getID();
			void setX(double x);
			void setY(double y);
			void setName(string name);
			void setReady(bool ready);
			void setMapLoaded(bool loaded);
			double getX();
			double getY();
			string getName();
			bool isReady();
			bool hasLoadedMap();
			void disconnect();
			void sendData(ENetHost* host, unsigned char* data, unsigned int length);
			void sendData(ENetHost* host, string& data);
			void sendMessage(ENetHost* host, NetworkMessage& message);
			void removeLife();
			bool isAlive();
	};
};

#endif
