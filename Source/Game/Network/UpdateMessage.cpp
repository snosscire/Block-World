#include "UpdateMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

#include <iostream>

using namespace BadEngine;

namespace BlockWorld {
	UpdateMessage::UpdateMessage() :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0),
		m_angle(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(0),
		m_moveRight(0),
		m_jump(0),
		m_jumping(0),
		m_touchingGround(0),
		m_health(0),
		m_currentAnimation("default")
	{
	}
	
	UpdateMessage::UpdateMessage(int id, double x, double y) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y),
		m_angle(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(0),
		m_moveRight(0),
		m_jump(0),
		m_jumping(0),
		m_touchingGround(0),
		m_health(0),
		m_currentAnimation("default")
	{
	}
	
	UpdateMessage::UpdateMessage(int id,
	                             double x,
	                             double y,
	                             double angle,
	                             double velocityX,
	                             double velocityY,
	                             bool jumping,
	                             bool touchingGround,
	                             int health) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y),
		m_angle(angle),
		m_velocityX(velocityX),
		m_velocityY(velocityY),
		m_moveLeft(0),
		m_moveRight(0),
		m_jump(0),
		m_jumping((jumping ? 1 : 0)),
		m_touchingGround((touchingGround ? 1 : 0)),
		m_health(health),
		m_currentAnimation("default")
	{
	}
	
	UpdateMessage::UpdateMessage(string& data) :
		NetworkMessage(),
		m_id(0),
		m_x(0.0),
		m_y(0.0),
		m_angle(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft(0),
		m_moveRight(0),
		m_jump(0),
		m_touchingGround(0),
		m_health(0),
		m_currentAnimation("default")
	{
		m_id = Network::readByteFromData(data);
		m_x = Network::readDoubleFromData(data);
		m_y = Network::readDoubleFromData(data);
		m_angle = Network::readDoubleFromData(data);
		m_velocityX = Network::readDoubleFromData(data);
		m_velocityY = Network::readDoubleFromData(data);
		//m_moveLeft = Network::readByteFromData(data);
		//m_moveRight = Network::readByteFromData(data);
		//m_jump = Network::readByteFromData(data);
		m_jumping = Network::readByteFromData(data);
		m_touchingGround = Network::readByteFromData(data);
		m_health = Network::readLongFromData(data);
		//Network::readStringFromData(data, m_currentAnimation);
	}
	
	UpdateMessage:: UpdateMessage(int id,
	                              double x,
	                              double y,
	                              bool moveLeft,
	                              bool moveRight,
	                              bool jump,
	                              bool touchingGround,
	                              string animation) :
		NetworkMessage(),
		m_id(id),
		m_x(x),
		m_y(y),
		m_angle(0.0),
		m_velocityX(0.0),
		m_velocityY(0.0),
		m_moveLeft((moveLeft ? 1 : 0)),
		m_moveRight((moveRight ? 1 : 0)),
		m_jump((jump ? 1 : 0 )),
		m_jumping(0),
		m_touchingGround((touchingGround ? 1 : 0)),
		m_health(0),
		m_currentAnimation(animation)
	{
	}	
	
	UpdateMessage::~UpdateMessage()
	{
	}
	
	int UpdateMessage::getID()
	{
		return m_id;
	}
	
	double UpdateMessage::getX()
	{
		return m_x;
	}
	
	double UpdateMessage::getY()
	{
		return m_y;
	}
	
	double UpdateMessage::getAngle()
	{
		return m_angle;
	}
	
	double UpdateMessage::getVelocityX()
	{
		return m_velocityX;
	}
	
	double UpdateMessage::getVelocityY()
	{
		return m_velocityY;
	}
	
	bool UpdateMessage::getMoveLeft()
	{
		return (m_moveLeft == 1 ? true : false);
	}
	
	bool UpdateMessage::getMoveRight()
	{
		return (m_moveRight == 1 ? true : false);
	}
	
	bool UpdateMessage::getJump()
	{
		return (m_jump == 1 ? true : false);
	}
	
	bool UpdateMessage::getJumping()
	{
		return (m_jumping == 1 ? true : false);
	}
	
	bool UpdateMessage::getTouchingGround()
	{
		return (m_touchingGround == 1 ? true : false);
	}
	
	int UpdateMessage::getHealth()
	{
		return m_health;
	}
	
	const string& UpdateMessage::getCurrentAnimation()
	{
		return m_currentAnimation;
	}
	
	string UpdateMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_UPDATE);
		Network::addByteToData(data, m_id);
		Network::addDoubleToData(data, m_x);
		Network::addDoubleToData(data, m_y);
		Network::addDoubleToData(data, m_angle);
		Network::addDoubleToData(data, m_velocityX);
		Network::addDoubleToData(data, m_velocityY);
		//Network::addByteToData(data, m_moveLeft);
		//Network::addByteToData(data, m_moveRight);
		//Network::addByteToData(data, m_jump);
		Network::addByteToData(data, m_jumping);
		Network::addByteToData(data, m_touchingGround);
		Network::addLongToData(data, m_health);
		//Network::addStringToData(data, m_currentAnimation);
		return data;
	}
};
