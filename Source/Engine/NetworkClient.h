#ifndef __BADENGINE_NETWORKCLIENT_H__
#define __BADENGINE_NETWORKCLIENT_H__

#include "Network.h"

namespace BadEngine {
	class NetworkClient : public Network {
		protected:
			ENetPeer* m_peer;
		
		public:
			NetworkClient();
			virtual ~NetworkClient();
			bool connect(string hostname, int port);
			void disconnect();
			void sendData(string& data);
	};
};

#endif
