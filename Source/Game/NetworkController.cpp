#include "NetworkController.h"
#include "GameObject.h"
#include "GameNetworkClient.h"
#include "Network/UpdateMessage.h"

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
			m_object->setVelocityX(message.getVelocityX());
			m_object->setVelocityY(message.getVelocityY());
			m_object->setJumping(message.getJumping());
			m_object->setTouchingGround(message.getTouchingGround());
			//m_object->setSpriteAnimation(message.getCurrentAnimation());
			//m_object->setMoveLeft(message.getMoveLeft());
			//m_object->setMoveRight(message.getMoveRight());
			//m_object->setJump(message.getJump());
		}
	}
};
