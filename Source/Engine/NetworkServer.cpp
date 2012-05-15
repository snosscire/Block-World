#include "NetworkServer.h"

namespace BadEngine {
	NetworkServer::NetworkServer() :
		Network()
	{
	}
	
	NetworkServer::~NetworkServer()
	{
		stop();
	}
	
	bool NetworkServer::start(int port)
	{
		ENetAddress address;
		address.host = ENET_HOST_ANY;
		address.port = port;
		
		m_host = enet_host_create(&address, 32, 0, 0, 0);
		if (m_host) {
			return true;
		}
		
		return false;
	}
	
	void NetworkServer::stop()
	{
		if (m_host) {
			enet_host_flush(m_host);
			enet_host_destroy(m_host);
			m_host = NULL;
		}
	}
};
