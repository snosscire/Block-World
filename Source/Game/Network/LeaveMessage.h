#ifndef __BLOCKWORLD_LEAVEMESSAGE_H__
#define __BLOCKWORLD_LEAVEMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class LeaveMessage : public NetworkMessage {
		private:
			int m_id;
		
		public:
			LeaveMessage();
			LeaveMessage(int id);
			LeaveMessage(string& data);
			virtual ~LeaveMessage();
			int getID();
			string toData();
	};
};

#endif
