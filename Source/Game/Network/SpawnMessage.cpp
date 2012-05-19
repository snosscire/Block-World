#include "SpawnMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	SpawnMessage::SpawnMessage() :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	SpawnMessage::SpawnMessage(int id, double x, double y) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y)
	{
	}
	
	SpawnMessage::SpawnMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
		m_id = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
	}
	
	SpawnMessage::~SpawnMessage()
	{
	}
	
	int SpawnMessage::getID()
	{
		return m_id;
	}
	
	double SpawnMessage::getX()
	{
		return m_x;
	}
	
	double SpawnMessage::getY()
	{
		return m_y;
	}
	
	string SpawnMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_SPAWN);
		Network::addByteToData(data, m_id);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		return data;
	}
};

