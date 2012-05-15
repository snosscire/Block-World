#ifndef __BLOCKWORLD_NETWORKMESSAGE_H__
#define __BLOCKWORLD_NETWORKMESSAGE_H__

#include <string>

using namespace std;

namespace BlockWorld {
	class NetworkMessage {		
		protected:
			NetworkMessage() { }
			virtual ~NetworkMessage() { }
		
		public:
			virtual string toData() = 0;
	};
};

#endif // __BLOCKWORLD_NETWORKMESSAGE_H__
