#include "IdentityMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	IdentityMessage::IdentityMessage(int id, string name) :
		NetworkMessage(),
		m_id(id),
		m_name(name)
	{
	}
	
	IdentityMessage::IdentityMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_name()
	{
		m_id = Network::readByteFromData(data);
		Network::readStringFromData(data, m_name);
	}
	
	IdentityMessage::~IdentityMessage()
	{
	}
	
	int IdentityMessage::getID()
	{
		return m_id;
	}
	
	string IdentityMessage::getName()
	{
		return m_name;
	}
	
	string IdentityMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_IDENTITY);
		Network::addByteToData(data, m_id);
		Network::addStringToData(data, m_name);
		return data;
	}
};

