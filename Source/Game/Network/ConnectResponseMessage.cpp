#include "ConnectResponseMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ConnectResponseMessage::ConnectResponseMessage() :
		NetworkMessage(),
		m_id(0)
	{
	}
	
	ConnectResponseMessage::ConnectResponseMessage(int id) :
		NetworkMessage(),
		m_id(id)
	{
	}
	
	ConnectResponseMessage::ConnectResponseMessage(string& data) :
		NetworkMessage(),
		m_id(0)
	{
		m_id = Network::readByteFromData(data);
	}
	
	ConnectResponseMessage::~ConnectResponseMessage()
	{
	}
	
	int ConnectResponseMessage::getID()
	{
		return m_id;
	}
	
	string ConnectResponseMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_CONNECT_RESPONSE);
		Network::addByteToData(data, m_id);
		return data;
	}
};

