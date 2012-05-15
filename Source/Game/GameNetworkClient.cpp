#include "GameNetworkClient.h"
#include "GameNetwork.h"
#include "GameObject.h"
#include "MessageObserver.h"

#include "Network/NetworkMessage.h"
#include "Network/ConnectResponseMessage.h"
#include "Network/JoinMessage.h"
#include "Network/LeaveMessage.h"
#include "Network/UpdateMessage.h"

#include <iostream>
#include <string>

namespace BlockWorld {
	GameNetworkClient::GameNetworkClient() :
		NetworkClient(),
		NetworkObserver(),
		m_messageObservers()
	{
		registerObserver(this);
	}
	
	GameNetworkClient::~GameNetworkClient()
	{
	}
	
	void GameNetworkClient::registerMessageObserver(MessageObserver* observer)
	{
		m_messageObservers.push_back(observer);
	}
	
	void GameNetworkClient::sendMessage(NetworkMessage& message)
	{
		string data = message.toData();
		Network::sendData(m_host, m_peer, data);
	}
	
	void GameNetworkClient::sendUpdate(GameObject& object)
	{
		/*
		UpdateMessage message(object.getNetworkID(),
		                      object.getX(),
		                      object.getY(),
		                      false,
		                      false,
		                      false,
		                      object.isTouchingGround(),
		                      object.getCurrentSpriteAnimation());
		*/
		UpdateMessage message(object.getNetworkID(),
		                      object.getX(),
		                      object.getY(),
		                      object.getVelocityX(),
		                      object.getVelocityY(),
		                      object.isJumping(),
		                      object.isTouchingGround());
		sendMessage(message);
	}
	
	void GameNetworkClient::sendUpdate(GameObject& object, bool moveLeft, bool moveRight, bool jump)
	{
		UpdateMessage message(object.getNetworkID(),
		                      object.getX(),
		                      object.getY(),
		                      moveLeft,
		                      moveRight,
		                      jump,
		                      object.isTouchingGround(),
		                      object.getCurrentSpriteAnimation());
		sendMessage(message);
	}
	
	void GameNetworkClient::onReceive(ENetPacket* packet)
	{
		string data;		
		for (unsigned int i = 0; i < packet->dataLength; i++) {
			data.push_back(packet->data[i]);
		}
		
		int type = Network::readByteFromData(data);
		
		list<MessageObserver*>::iterator it;
		
		switch (type) {
			case GameNetwork::MESSAGE_CONNECT_RESPONSE: {
				ConnectResponseMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onConnectResponse(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_JOIN: {
				JoinMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onJoin(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_LEAVE:{
				LeaveMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onLeave(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_UPDATE: {
				UpdateMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onUpdate(message);
				}
				break;
			}
		}
		
	}
};

