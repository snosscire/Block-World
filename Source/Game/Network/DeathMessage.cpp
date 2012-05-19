#include "DeathMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	DeathMessage::DeathMessage() :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	DeathMessage::DeathMessage(int id, double x, double y) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y)
	{
	}
	
	DeathMessage::DeathMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
		m_id = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
	}
	
	DeathMessage::~DeathMessage()
	{
	}
	
	int DeathMessage::getID()
	{
		return m_id;
	}
	
	double DeathMessage::getX()
	{
		return m_x;
	}
	
	double DeathMessage::getY()
	{
		return m_y;
	}
	
	string DeathMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_DEATH);
		Network::addByteToData(data, m_id);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		return data;
	}
};

