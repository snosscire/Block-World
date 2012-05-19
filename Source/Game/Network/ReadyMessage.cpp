#include "ReadyMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ReadyMessage::ReadyMessage() :
		NetworkMessage(),
		m_id(0)
	{
	}
	
	ReadyMessage::ReadyMessage(int id) :
		NetworkMessage(),
		m_id(id)
	{
	}
	
	ReadyMessage::ReadyMessage(string& data) :
		NetworkMessage(),
		m_id(0)
	{
		m_id = Network::readByteFromData(data);
	}
	
	ReadyMessage::~ReadyMessage()
	{
	}
	
	int ReadyMessage::getID()
	{
		return m_id;
	}
	
	string ReadyMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_READY);
		Network::addByteToData(data, m_id);
		return data;
	}
};
