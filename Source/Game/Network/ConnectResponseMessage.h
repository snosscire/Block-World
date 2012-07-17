#ifndef __BLOCKWORLD_CONNECTRESPONSEMESSAGE_H__
#define __BLOCKWORLD_CONNECTRESPONSEMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class ConnectResponseMessage : public NetworkMessage {
		private:
			int m_id;
			int m_gameInProgress;
		
		public:
			ConnectResponseMessage();
			ConnectResponseMessage(int id, bool gameInProgress);
			ConnectResponseMessage(string& data);
			virtual ~ConnectResponseMessage();
			int getID();
			bool getGameInProgress();
			string toData();
	};
};

#endif
