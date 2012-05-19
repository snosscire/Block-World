#ifndef __BLOCKWORLD_MAPLOADEDMESSAGE_H__
#define __BLOCKWORLD_MAPLOADEDMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class MapLoadedMessage : public NetworkMessage {
		private:
			int m_id;
		
		public:
			MapLoadedMessage();
			MapLoadedMessage(int id);
			MapLoadedMessage(string& data);
			virtual ~MapLoadedMessage();
			int getID();
			string toData();
	};
};

#endif
