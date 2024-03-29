#include "JoinMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

#include <iostream>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	JoinMessage::JoinMessage() :
		NetworkMessage(),
		m_id(0),
		m_name()
	{
	}
	
	JoinMessage::JoinMessage(int id, string name) :
		NetworkMessage(),
		m_id(id),
		m_name(name)
	{
	}
	
	JoinMessage::JoinMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_name()
	{
		m_id = Network::readByteFromData(data);
		Network::readStringFromData(data, m_name);
	}
	
	JoinMessage::~JoinMessage()
	{
	}
	
	int JoinMessage::getID()
	{
		return m_id;
	}
	
	string JoinMessage::getName()
	{
		return m_name;
	}
	
	string JoinMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_JOIN);
		Network::addByteToData(data, m_id);
		Network::addStringToData(data, m_name);
		return data;
	}
};

