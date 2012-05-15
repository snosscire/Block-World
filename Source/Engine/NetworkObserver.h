#ifndef __BADENGINE_NETWORKOBSERVER_H__
#define __BADENGINE_NETWORKOBSERVER_H__

#include <enet/enet.h>

namespace BadEngine {
	class NetworkObserver {
		protected:
			NetworkObserver() { }
			virtual ~NetworkObserver() { }
		
		public:
			virtual void onConnect(ENetPeer* peer) {}
			virtual void onDisconnect(ENetPeer* peer) {}
			virtual void onReceive(ENetPacket* packet) {}
	};
};

#endif // __BADENGINE_NETWORKOBSERVER_H__
