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
		m_x(0.0),
		m_y(0.0)
	{
	}
	
	JoinMessage::JoinMessage(int id, double x, double y) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y)
	{
	}
	
	JoinMessage::JoinMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0)
	{
		m_id = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
	}
	
	JoinMessage::~JoinMessage()
	{
	}
	
	int JoinMessage::getID()
	{
		return m_id;
	}
	
	double JoinMessage::getX()
	{
		return m_x;
	}
	
	double JoinMessage::getY()
	{
		return m_y;
	}
	
	string JoinMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_JOIN);
		Network::addByteToData(data, m_id);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		return data;
	}
};

