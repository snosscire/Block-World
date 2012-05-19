#ifndef __BLOCKWORLD_SPAWNMESSAGE_H__
#define __BLOCKWORLD_SPAWNMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class SpawnMessage : public NetworkMessage {
		private:
			int m_id;
			double m_x;
			double m_y;
		
		public:
			SpawnMessage();
			SpawnMessage(int id, double x, double y);
			SpawnMessage(string& data);
			virtual ~SpawnMessage();
			int getID();
			double getX();
			double getY();
			string toData();
	};
};

#endif
