#ifndef __BLOCKWORLD_LOADMAPMESSAGE_H__
#define __BLOCKWORLD_LOADMAPMESSAGE_H__

#include "NetworkMessage.h"

#include <string>

using namespace std;

namespace BlockWorld {
	class LoadMapMessage : public NetworkMessage {
		private:
			int m_players;
			string m_name;
		
		public:
			LoadMapMessage();
			LoadMapMessage(int players, string name);
			LoadMapMessage(string& data);
			virtual ~LoadMapMessage();
			int getPlayers();
			string getName();
			string toData();
	};
};

#endif
