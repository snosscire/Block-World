#ifndef __BLOCKWORLD_JOINMESSAGE_H__
#define __BLOCKWORLD_JOINMESSAGE_H__

#include "NetworkMessage.h"

#include <string>

using namespace std;

namespace BlockWorld {
	class JoinMessage : public NetworkMessage {
		private:
			int m_id;
			string m_name;
		
		public:
			JoinMessage();
			JoinMessage(int id, string name);
			JoinMessage(string& data);
			virtual ~JoinMessage();
			int getID();
			string getName();
			string toData();
	};
};

#endif

