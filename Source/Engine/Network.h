#ifndef __BADENGINE_NETWORK_H__
#define __BADENGINE_NETWORK_H__

#include <enet/enet.h>

#include <list>
#include <string>

using namespace std;

namespace BadEngine {
	class NetworkObserver;
	class Network {
		private:
			list<NetworkObserver*> m_observers;
		
		protected:
			ENetHost* m_host;
		
		public:
			static long byteToNumber(unsigned char byte);
			static void addByteToData(string& data, int value);
			static void addShortToData(string& data, int value);
			static void addLongToData(string& data, int value);
			static void addDoubleToData(string& data, double value);
			static void addStringToData(string& data, string value);
			static int readByteFromData(string& data);
			static int readShortFromData(string& data);
			static int readLongFromData(string& data);
			static double readDoubleFromData(string& data);
			static void readStringFromData(string& data, string& content);
			static void sendData(ENetHost* host, ENetPeer* peer, string& data);
			static void sendData(ENetHost* host, ENetPeer* peer, unsigned char* data, unsigned int length);
			
			Network();
			virtual ~Network();
			
			void notifyObservers(int timeout = 0);
			void registerObserver(NetworkObserver* observer);
			void unregisterObserver(NetworkObserver* observer);
	};
};

#endif // __BADENGINE_NETWORK_H__
