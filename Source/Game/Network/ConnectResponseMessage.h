#ifndef __BLOCKWORLD_CONNECTRESPONSEMESSAGE_H__
#define __BLOCKWORLD_CONNECTRESPONSEMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class ConnectResponseMessage : public NetworkMessage {
		private:
			int m_id;
		
		public:
			ConnectResponseMessage();
			ConnectResponseMessage(int id);
			ConnectResponseMessage(string& data);
			virtual ~ConnectResponseMessage();
			int getID();
			string toData();
	};
};

#endif
