#include "ConnectMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ConnectMessage::ConnectMessage() :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	ConnectMessage::ConnectMessage(int id, double x, double y) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y)
	{
	}
	
	ConnectMessage::ConnectMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
		m_id = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
	}
	
	ConnectMessage::~ConnectMessage()
	{
	}
	
	int ConnectMessage::getID()
	{
		return m_id;
	}
	
	double ConnectMessage::getX()
	{
		return m_x;
	}
	
	double ConnectMessage::getY()
	{
		return m_y;
	}
	
	string ConnectMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_CONNECT);
		Network::addByteToData(data, m_id);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		return data;
	}
};
