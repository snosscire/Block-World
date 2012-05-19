#ifndef __BLOCKWORLD_READYMESSAGE_H__
#define __BLOCKWORLD_READYMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class ReadyMessage : public NetworkMessage {
		private:
			int m_id;
		
		public:
			ReadyMessage();
			ReadyMessage(int id);
			ReadyMessage(string& data);
			virtual ~ReadyMessage();
			int getID();
			string toData();
	};
};

#endif
