#ifndef __BLOCKWORLD_STARTGAMEMESSAGE_H__
#define __BLOCKWORLD_STARTGAMEMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class StartGameMessage : public NetworkMessage {
		public:
			StartGameMessage();
			StartGameMessage(string& data);
			virtual ~StartGameMessage();
			string toData();
	};
};

#endif
