#include "NetworkClient.h"

namespace BadEngine {
	NetworkClient::NetworkClient() :
		Network(),
		m_peer(NULL)
	{
	}
	
	NetworkClient::~NetworkClient()
	{
		if (m_peer) {
			enet_peer_disconnect_now(m_peer, 0);
		}
	}
	
	bool NetworkClient::connect(string hostname, int port)
	{
		ENetAddress address;
		enet_address_set_host(&address, hostname.c_str());
		address.port = port;
		
		m_host = enet_host_create(NULL, 1, 0, 0, 0);
		
		if (m_host) {
			m_peer = enet_host_connect(m_host, &address, 2, 0);
			
			if (m_peer) {
				return true;
			}
			
		}
		
		return false;
	}
	
	void NetworkClient::disconnect()
	{
		if (m_host) {
			enet_peer_disconnect_now(m_peer, 0);
			enet_host_destroy(m_host);
			m_host = NULL;
			m_peer = NULL;
		}
	}
	
	void NetworkClient::sendData(string& data)
	{
		Network::sendData(m_host, m_peer, data);
	}
};
