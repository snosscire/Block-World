#ifndef __BLOCKWORLD_JOINMESSAGE_H__
#define __BLOCKWORLD_JOINMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class JoinMessage : public NetworkMessage {
		private:
			int m_id;
			double m_x;
			double m_y;
		
		public:
			JoinMessage();
			JoinMessage(int id, double x, double y);
			JoinMessage(string& data);
			virtual ~JoinMessage();
			int getID();
			double getX();
			double getY();
			string toData();
	};
};

#endif

