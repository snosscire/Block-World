#ifndef __BLOCKWORLD_ENDGAMEMESSAGE_H__
#define __BLOCKWORLD_ENDGAMEMESSAGE_H__

#include "NetworkMessage.h"

#include <string>

using namespace std;

namespace BlockWorld {
	class EndGameMessage : public NetworkMessage {
		private:
			int m_players;
			string m_winner;
		
		public:
			EndGameMessage(int players, string winner);
			EndGameMessage(string& data);
			virtual ~EndGameMessage();
			string toData();
			int getPlayers();
			string getWinner();
	};
};

#endif
