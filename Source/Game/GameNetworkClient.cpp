#include "GameNetworkClient.h"
#include "GameNetwork.h"
#include "GameObject.h"
#include "MessageObserver.h"

#include "Network/NetworkMessage.h"
#include "Network/ConnectResponseMessage.h"
#include "Network/JoinMessage.h"
#include "Network/LeaveMessage.h"
#include "Network/LoadMapMessage.h"
#include "Network/StartGameMessage.h"
#include "Network/SpawnMessage.h"
#include "Network/UpdateMessage.h"
#include "Network/ShotMessage.h"
#include "Network/DeathMessage.h"

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
		UpdateMessage message(object.getNetworkID(),
		                      object.getX(),
		                      object.getY(),
		                      object.getAngle(),
		                      object.getVelocityX(),
		                      object.getVelocityY(),
		                      object.isJumping(),
		                      object.isTouchingGround(),
		                      object.getHealth());
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
			case GameNetwork::MESSAGE_LOAD_MAP:{
				LoadMapMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onLoadMap(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_START_GAME:{
				StartGameMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onStartGame(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_SPAWN:{
				SpawnMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onSpawn(message);
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
			case GameNetwork::MESSAGE_SHOT: {
				ShotMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onShot(message);
				}
				break;
			}
			case GameNetwork::MESSAGE_DEATH: {
				DeathMessage message(data);
				it = m_messageObservers.begin();
				for ( ; it != m_messageObservers.end(); it++) {
					(*it)->onDeath(message);
				}
				break;
			}
		}
		
	}
};

