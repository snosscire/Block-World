#include "MapLoadedMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	MapLoadedMessage::MapLoadedMessage() :
		NetworkMessage(),
		m_id(0)
	{
	}
	
	MapLoadedMessage::MapLoadedMessage(int id) :
		NetworkMessage(),
		m_id(id)
	{
	}
	
	MapLoadedMessage::MapLoadedMessage(string& data) :
		NetworkMessage(),
		m_id(0)
	{
		m_id = Network::readByteFromData(data);
	}
	
	MapLoadedMessage::~MapLoadedMessage()
	{
	}
	
	int MapLoadedMessage::getID()
	{
		return m_id;
	}
	
	string MapLoadedMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_MAP_LOADED);
		Network::addByteToData(data, m_id);
		return data;
	}
};

