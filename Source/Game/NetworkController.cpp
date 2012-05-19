#include "NetworkController.h"
#include "GameObject.h"
#include "GameNetworkClient.h"
#include "Network/UpdateMessage.h"
#include "Network/ShotMessage.h"
#include "Weapon.h"

#include <iostream>

namespace BlockWorld {
	NetworkController::NetworkController() :
		ObjectController(NULL),
		MessageObserver(),
		m_network(NULL)
	{
	}
	
	NetworkController::NetworkController(GameObject& object, GameNetworkClient& network) :
		ObjectController(&object),
		MessageObserver(),
		m_network(&network)
	{
		network.registerMessageObserver(this);
	}
	
	NetworkController::~NetworkController()
	{
		// TODO: Unregister as message observer
	}
	
	void NetworkController::onUpdate(UpdateMessage& message)
	{
		if (message.getID() == m_object->getNetworkID()) {
			m_object->setX(message.getX());
			m_object->setY(message.getY());
			m_object->setAngle(message.getAngle());
			m_object->setVelocityX(message.getVelocityX());
			m_object->setVelocityY(message.getVelocityY());
			m_object->setJumping(message.getJumping());
			m_object->setTouchingGround(message.getTouchingGround());
			m_object->setHealth(message.getHealth());
			//m_object->setSpriteAnimation(message.getCurrentAnimation());
			//m_object->setMoveLeft(message.getMoveLeft());
			//m_object->setMoveRight(message.getMoveRight());
			//m_object->setJump(message.getJump());
		}
	}
	
	void NetworkController::onShot(ShotMessage& message)
	{
		if (message.getID() == m_object->getNetworkID()) {
			Weapon* weapon = m_object->getWeapon();
			if (weapon) {
				weapon->fireBullet(message.getX(), message.getY(), message.getAngle());
			}
		}
	}
};

