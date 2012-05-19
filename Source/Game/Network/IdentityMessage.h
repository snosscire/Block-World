#ifndef __BLOCKWORLD_IDENTITYMESSAGE_H__
#define __BLOCKWORLD_IDENTITYMESSAGE_H__

#include "NetworkMessage.h"

#include <string>

using namespace std;

namespace BlockWorld {
	class IdentityMessage : public NetworkMessage {
		private:
			int m_id;
			string m_name;
		
		public:
			IdentityMessage(int id, string name);
			IdentityMessage(string& data);
			~IdentityMessage();
			int getID();
			string getName();
			string toData();
	};
};

#endif
