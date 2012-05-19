#ifndef __BLOCKWORLD_DEATHMESSAGE_H__
#define __BLOCKWORLD_DEATHMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class DeathMessage : public NetworkMessage {
		private:
			int m_id;
			double m_x;
			double m_y;
		
		public:
			DeathMessage();
			DeathMessage(int id, double x, double y);
			DeathMessage(string& data);
			virtual ~DeathMessage();
			int getID();
			double getX();
			double getY();
			string toData();
	};
};

#endif
