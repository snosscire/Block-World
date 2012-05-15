#ifndef __BLOCKWORLD_CONNECTMESSAGE_H__
#define __BLOCKWORLD_CONNECTMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class ConnectMessage : public NetworkMessage {
		private:
			int m_id;
			double m_x;
			double m_y;
		
		public:
			ConnectMessage();
			ConnectMessage(int id, double x, double y);
			ConnectMessage(string& data);
			virtual ~ConnectMessage();
			int getID();
			double getX();
			double getY();
			string toData();
	};
};

#endif
