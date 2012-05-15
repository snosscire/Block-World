#ifndef __BLOCKWORLD_NETWORKCONTROLLER_H__
#define __BLOCKWORLD_NETWORKCONTROLLER_H__

#include "ObjectController.h"
#include "MessageObserver.h"

namespace BlockWorld {
	class GameNetworkClient;
	class UpdateMessage;
	class NetworkController : public ObjectController, public MessageObserver {
		private:
			GameNetworkClient* m_network;
		
		private:
			NetworkController();
		
		public:
			NetworkController(GameObject& object, GameNetworkClient& network);
			virtual ~NetworkController();
			void onUpdate(UpdateMessage& message);
	};
};

#endif
