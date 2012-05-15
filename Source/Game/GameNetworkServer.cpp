#include "GameNetworkServer.h"
#include "ServerClient.h"
#include "GameNetwork.h"
#include "GameObject.h"

#include "Network/ConnectMessage.h"
#include "Network/ConnectResponseMessage.h"
#include "Network/JoinMessage.h"
#include "Network/LeaveMessage.h"
#include "Network/UpdateMessage.h"

#include <iostream>

namespace BlockWorld {
	GameNetworkServer::GameNetworkServer() :
		NetworkServer(),
		NetworkObserver(),
		m_lastClientID(0),
		m_clients()
	{
		registerObserver(this);
	}
	
	GameNetworkServer::~GameNetworkServer()
	{
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			delete it->second;
		}
	}
	
	void GameNetworkServer::sendToAll(unsigned char* data, unsigned int length)
	{
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			it->second->sendData(m_host, data, length);
		}
	}
	
	void GameNetworkServer::sendToAll(string& data)
	{
		sendToAll((unsigned char*)data.c_str(), data.length());
	}
	
	void GameNetworkServer::sendToAllExcept(unsigned char* data, unsigned int length, int clientID)
	{
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			if (it->second->getID() != clientID) {
				it->second->sendData(m_host, data, length);
			}
		}
	}
	
	void GameNetworkServer::sendToAllExcept(string& data, int clientID)
	{
		sendToAllExcept((unsigned char*)data.c_str(), data.length(), clientID);
	}
	
	void GameNetworkServer::onConnect(ENetPeer* peer)
	{
		cout << "Got new connection." << endl;
		
		int* clientID = new int(); 
		*clientID = m_lastClientID + 1;
		
		ServerClient* client = new ServerClient(*clientID, peer);
		m_clients.insert(pair<int, ServerClient*>(*clientID, client));
		peer->data = clientID;
		
		cout << "Sending connect response..." << endl;
		
		ConnectResponseMessage message(*clientID);
		string data = message.toData();
		client->sendData(m_host, data);
		
		m_lastClientID = *clientID;
	}
	
	void GameNetworkServer::onDisconnect(ENetPeer* peer)
	{
		cout << "Client disconnected." << endl;
		
		int* clientID = static_cast<int*>(peer->data);
		m_clients.erase(*clientID);
		
		LeaveMessage message(*clientID);
		string data = message.toData();
		sendToAll(data);
		
		delete clientID;
		peer->data = NULL;
	}
	
	void GameNetworkServer::onReceive(ENetPacket* packet)
	{
		string data;
		
		for (unsigned int i = 0; i < packet->dataLength; i++) {
			data.push_back(packet->data[i]);
		}
		
		int type = Network::readByteFromData(data);
		
		switch (type) {
			case GameNetwork::MESSAGE_CONNECT: {
				ConnectMessage message(data);
				handleConnectMessage(message);
				break;
			} case GameNetwork::MESSAGE_UPDATE: {
				UpdateMessage message(data);
				handleUpdateMessage(message, packet);
				break;
			}
		}
	}
	
	void GameNetworkServer::handleConnectMessage(ConnectMessage& connectMessage)
	{
		cout << "Sending join message..." << endl;
		
		// Check if we have a player with this id
		map<int, ServerClient*>::iterator it = m_clients.find(connectMessage.getID());
		
		if (it != m_clients.end()) {
			// Update ServerClient object with position
			ServerClient* client = it->second;
			client->setX(connectMessage.getX());
			client->setY(connectMessage.getY());
			
			// Send join message about new player to all current players
			JoinMessage joinMessage(connectMessage.getID(), connectMessage.getX(), connectMessage.getY());
			string data = joinMessage.toData();
			sendToAllExcept(data, connectMessage.getID());
		
			// Send positions of all current players to connecting player
			map<int, ServerClient*>::iterator it;
			it = m_clients.begin();
			for ( ; it != m_clients.end(); it++) {
				if (it->second->getID() != connectMessage.getID()) {
					JoinMessage joinMessage(it->second->getID(), it->second->getX(), it->second->getY());
					client->sendMessage(m_host, joinMessage);
				}
			}
		}
	}
	
	void GameNetworkServer::handleUpdateMessage(UpdateMessage& updateMessage, ENetPacket* packet)
	{
		map<int, ServerClient*>::iterator it = m_clients.find(updateMessage.getID());
		if (it != m_clients.end()) {
			it->second->setX(updateMessage.getX());
			it->second->setY(updateMessage.getY());
			
			// Send update message to all other connected players
			sendToAllExcept((unsigned char*)packet->data, packet->dataLength, it->second->getID());
			
			/*
			UpdateMessage message(updateMessage.getID(), updateMessage.getX(), updateMessage.getY());		
			map<int, ServerClient*>::iterator it;
			it = m_clients.begin();
			for ( ; it != m_clients.end(); it++) {
				if (it->second->getID() != updateMessage.getID()) {	
					it->second->sendMessage(m_host, message);
				}
			}
			*/
		}
	}
};
