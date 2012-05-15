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
		
		private:
			ServerClient();
		
		public:
			ServerClient(int id, ENetPeer* peer);
			virtual ~ServerClient();
			int getID();
			void setX(double x);
			void setY(double y);
			double getX();
			double getY();
			void disconnect();
			void sendData(ENetHost* host, unsigned char* data, unsigned int length);
			void sendData(ENetHost* host, string& data);
			void sendMessage(ENetHost* host, NetworkMessage& message);
	};
};

#endif
