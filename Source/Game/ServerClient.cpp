#include "ServerClient.h"
#include "GameObject.h"
#include "Network/NetworkMessage.h"

#include "../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ServerClient::ServerClient() :
		m_id(0),
		m_peer(NULL),
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	ServerClient::ServerClient(int id, ENetPeer* peer) :
		m_id(id),
		m_peer(peer),
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	ServerClient::~ServerClient()
	{
	}
	
	int ServerClient::getID()
	{
		return m_id;
	}
	
	void ServerClient::setX(double x)
	{
		m_x = x;
	}
	
	void ServerClient::setY(double y)
	{
		m_y = y;
	}
	
	double ServerClient::getX()
	{
		return m_x;
	}
	
	double ServerClient::getY()
	{
		return m_y;
	}
	
	void ServerClient::disconnect()
	{
		enet_peer_disconnect_now (m_peer, 0);
	}
	
	void ServerClient::sendData(ENetHost* host, unsigned char* data, unsigned int length)
	{
		Network::sendData(host, m_peer, data, length);
	}
	
	void ServerClient::sendData(ENetHost* host, string& data)
	{
		Network::sendData(host, m_peer, (unsigned char*)data.c_str(), data.length());
	}
	
	void ServerClient::sendMessage(ENetHost* host, NetworkMessage& message)
	{
		string data = message.toData();
		sendData(host, data);
	}
};

