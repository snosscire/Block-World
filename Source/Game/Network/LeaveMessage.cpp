#include "LeaveMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	LeaveMessage::LeaveMessage() :
		NetworkMessage(),
		m_id(0)
	{
	}
	
	LeaveMessage::LeaveMessage(int id) :
		NetworkMessage(),
		m_id(id)
	{
	}
	
	LeaveMessage::LeaveMessage(string& data) :
		NetworkMessage(),
		m_id(0)
	{
		m_id = Network::readByteFromData(data);
	}
	
	LeaveMessage::~LeaveMessage()
	{
	}
	
	int LeaveMessage::getID()
	{
		return m_id;
	}
	
	string LeaveMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_LEAVE);
		Network::addByteToData(data, m_id);
		return data;
	}
};
