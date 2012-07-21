#include "ConnectResponseMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ConnectResponseMessage::ConnectResponseMessage() :
		NetworkMessage(),
		m_id(0),
		m_gameInProgress(0)
	{
	}
	
	ConnectResponseMessage::ConnectResponseMessage(int id, bool gameInProgress) :
		NetworkMessage(),
		m_id(id),
		m_gameInProgress((gameInProgress ? 1 : 0))
	{
	}
	
	ConnectResponseMessage::ConnectResponseMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_gameInProgress(0)
	{
		m_id = Network::readByteFromData(data);
		m_gameInProgress = Network::readByteFromData(data);
	}
	
	ConnectResponseMessage::~ConnectResponseMessage()
	{
	}
	
	int ConnectResponseMessage::getID()
	{
		return m_id;
	}
	
	bool ConnectResponseMessage::getGameInProgress()
	{
		return (m_gameInProgress ? true : false);
	}
	
	string ConnectResponseMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_CONNECT_RESPONSE);
		Network::addByteToData(data, m_id);
		Network::addByteToData(data, m_gameInProgress);
		return data;
	}
};

