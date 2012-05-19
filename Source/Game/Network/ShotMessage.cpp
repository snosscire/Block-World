#include "ShotMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	ShotMessage::ShotMessage() :
		NetworkMessage(),
		m_id(0),
		m_weapon(0),
		m_x(0.0),
		m_y(0.0),
		m_angle(0.0)
	{
	}
	
	ShotMessage::ShotMessage(int id, int weapon, double x, double y, double angle) :
		NetworkMessage(),
		m_id(id),
		m_weapon(weapon),
		m_x(x),
		m_y(y),
		m_angle(angle)
	{
	}
	
	ShotMessage::ShotMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_weapon(0),
		m_x(0.0),
		m_y(0.0),
		m_angle(0.0)
	{
		m_id = Network::readByteFromData(data);
		m_weapon = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
		m_angle = Network::readDoubleFromData(data);
	}
	
	ShotMessage::~ShotMessage()
	{
	}
	
	int ShotMessage::getID()
	{
		return m_id;
	}
	
	int ShotMessage::getWeapon()
	{
		return m_weapon;
	}
	
	double ShotMessage::getX()
	{
		return m_x;
	}
	
	double ShotMessage::getY()
	{
		return m_y;
	}
	
	double ShotMessage::getAngle()
	{
		return m_angle;
	}
	
	string ShotMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_SHOT);
		Network::addByteToData(data, m_id);
		Network::addByteToData(data, m_weapon);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		Network::addDoubleToData(data, m_angle);
		return data;
	}
};
