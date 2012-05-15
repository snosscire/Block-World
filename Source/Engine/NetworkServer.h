#ifndef __BADENGINE_NETWORKSERVER_H__
#define __BADENGINE_NETWORKSERVER_H__

#include "Network.h"

namespace BadEngine {
	class NetworkServer : public Network {
		public:
			NetworkServer();
			virtual ~NetworkServer();
			bool start(int port);
			void stop();
	};
};

#endif