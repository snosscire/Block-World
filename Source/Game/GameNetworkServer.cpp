#include "GameNetworkServer.h"
#include "ServerClient.h"
#include "GameNetwork.h"
#include "GameObject.h"

#include "Network/NetworkMessage.h"
#include "Network/ConnectResponseMessage.h"
#include "Network/IdentityMessage.h"
#include "Network/JoinMessage.h"
#include "Network/LeaveMessage.h"
#include "Network/ReadyMessage.h"
#include "Network/LoadMapMessage.h"
#include "Network/MapLoadedMessage.h"
#include "Network/StartGameMessage.h"
#include "Network/SpawnMessage.h"
#include "Network/UpdateMessage.h"
#include "Network/ShotMessage.h"
#include "Network/DeathMessage.h"
#include "Network/EndGameMessage.h"

#include <iostream>

namespace BlockWorld {
	GameNetworkServer::GameNetworkServer() :
		NetworkServer(),
		NetworkObserver(),
		m_gameInProgress(false),
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
	
	void GameNetworkServer::sendToAll(NetworkMessage& message)
	{
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			it->second->sendMessage(m_host, message);
		}
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
	
	void GameNetworkServer::sendToAllExcept(NetworkMessage& message, int clientID)
	{
		string data = message.toData();
		sendToAllExcept(data, clientID);
	}
	
	ServerClient* GameNetworkServer::getClient(int id)
	{
		map<int, ServerClient*>::iterator it = m_clients.find(id);
		if (it != m_clients.end()) {
			return it->second;
		}
		return NULL;
	}
	
	void GameNetworkServer::onConnect(ENetPeer* peer)
	{
		cout << "Got new connection." << endl;
		
		if (m_clients.size() < 4) {
			int* clientID = new int(); 
			*clientID = m_lastClientID + 1;
		
			ServerClient* client = new ServerClient(*clientID, peer);
			m_clients.insert(pair<int, ServerClient*>(*clientID, client));
			peer->data = clientID;
		
			cout << "Sending connect confirmation." << endl;
		
			ConnectResponseMessage message(*clientID, false);
			string data = message.toData();
			client->sendData(m_host, data);
		
			m_lastClientID = *clientID;
		} else {
			ServerClient* client = new ServerClient(0, peer);
			ConnectResponseMessage message(0, true);
			string data = message.toData();
			client->sendData(m_host, data);
			delete client;
		}
	}
	
	void GameNetworkServer::onDisconnect(ENetPeer* peer)
	{
		cout << "Client disconnected." << endl;
		
		if (peer->data) {
			int* clientID = static_cast<int*>(peer->data);
		
			ServerClient* client = getClient(*clientID);
		
			if (client) {
				m_clients.erase(*clientID);
			
				LeaveMessage message(*clientID);
				string data = message.toData();
				sendToAll(data);
			
			
				//if (m_clients.size() == 1) {
				//	m_gameInProgress = false;
				//	if (playersAlive() <= 1) {
				//		sendEndGameMessage();
				//	}
				//}
			}

			delete clientID;
			peer->data = NULL;
		}
	}
	
	void GameNetworkServer::onReceive(ENetPacket* packet)
	{
		string data;
		
		for (unsigned int i = 0; i < packet->dataLength; i++) {
			data.push_back(packet->data[i]);
		}
		
		int type = Network::readByteFromData(data);
		
		switch (type) {
			case GameNetwork::MESSAGE_IDENTITY: {
				IdentityMessage message(data);
				handleIdentityMessage(message);
				break;
			} case GameNetwork::MESSAGE_READY: {
				ReadyMessage message(data);
				handleReadyMessage(message);
				break;
			} case GameNetwork::MESSAGE_MAP_LOADED: {
				MapLoadedMessage message(data);
				handleMapLoadedMessage(message);
				break;
			} case GameNetwork::MESSAGE_SPAWN: {
				SpawnMessage message(data);
				handleSpawnMessage(message, packet);
				break;
			} case GameNetwork::MESSAGE_UPDATE: {
				UpdateMessage message(data);
				handleUpdateMessage(message, packet);
				break;
			} case GameNetwork::MESSAGE_SHOT: {
				ShotMessage message(data);
				handleShotMessage(message, packet);
				break;
			} case GameNetwork::MESSAGE_DEATH: {
				DeathMessage message(data);
				handleDeathMessage(message, packet);
				break;
			}
		}
	}
	
	void GameNetworkServer::handleIdentityMessage(IdentityMessage& message)
	{
		// We have now received the identity message from the player.
		// Lets send the player list to the new players.
		
		ServerClient* client = getClient(message.getID());
		if (client) {
			// Update the name of the new player with the name in the identity message
			client->setName(message.getName());
			
			// Send the new player the list of already connected players.
			//map<int, ServerClient*>::iterator it = m_clients.begin();
			//for ( ; it != m_clients.end(); it++) {
			//	if (it->second->getID() != client->getID()) {
			//		JoinMessage join(it->second->getID(), it->second->getName());
			//		client->sendMessage(m_host, join);
			//	}
			//}

			// Send a message to the already connected players telling them
			// about the new player.
			//if (!m_gameInProgress) {
			//	JoinMessage join(client->getID(), client->getName());
			//	sendToAllExcept(join, client->getID());
			//}
		}
	}
	
	void GameNetworkServer::handleReadyMessage(ReadyMessage& message)
	{
		cout << "Handling ready message." << endl;
		if (m_clients.size() < 5) {
			ServerClient* client = getClient(message.getID());
			if (client) {
				cout << "Setting client to ready." << endl;
				client->setReady(true);
			
				// Check if all clients now are ready so the game can be started.
				bool allClientsReady = true;
			
				map<int, ServerClient*>::iterator it;
				it = m_clients.begin();
				for ( ; it != m_clients.end(); it++) {
					if (!it->second->isReady()) {
						allClientsReady = false;
						break;
					}
				}
			
				// If clients are ready send the load map message and tell
				// the clients what map to load.
				if (allClientsReady) {
					m_gameInProgress = true;
					cout << "Asking clients to load the map." << endl;
					LoadMapMessage loadMessage(m_clients.size(), "test1");
					sendToAll(loadMessage);
				} else {
					cout << "All clients are not ready yet." << endl;
				}
			} else {
				cout << "Could not find client." << endl;
			}
		} else {
			cout << "A game is already in progress. Not accepting ready commands." << endl;
		}
	}
	
	void GameNetworkServer::handleMapLoadedMessage(MapLoadedMessage& message)
	{
		ServerClient* client = getClient(message.getID());
		if (client) {
			client->setMapLoaded(true);
			
			// Check if all clients now have the map loaded.
			bool allClientsHaveLoaded = true;
			
			map<int, ServerClient*>::iterator it;
			it = m_clients.begin();
			for ( ; it != m_clients.end(); it++) {
				if (!it->second->hasLoadedMap()) {
					allClientsHaveLoaded = false;
					break;
				}
			}
			
			// If all clients have loaded the map it is time to send
			// the start message which tells the clients to start
			// the game.
			if (allClientsHaveLoaded) {
				StartGameMessage startMessage;
				sendToAll(startMessage);
			}
		}
	}
	
	void GameNetworkServer::handleUpdateMessage(UpdateMessage& message, ENetPacket* packet)
	{
		ServerClient* client = getClient(message.getID());
		if (client) {
			client->setX(message.getX());
			client->setY(message.getY());
			
			// Send update message to all other connected players
			sendToAllExcept((unsigned char*)packet->data, packet->dataLength, client->getID());
			
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
	
	void GameNetworkServer::handleSpawnMessage(SpawnMessage& message, ENetPacket* packet)
	{
		ServerClient* client = getClient(message.getID());
		if (client) {
			client->setX(message.getX());
			client->setY(message.getY());
			
			sendToAllExcept((unsigned char*)packet->data, packet->dataLength, client->getID());
		}
	}

	void GameNetworkServer::handleShotMessage(ShotMessage& message, ENetPacket* packet)
	{
		ServerClient* client = getClient(message.getID());
		if (client) {
			sendToAllExcept((unsigned char*)packet->data, packet->dataLength, client->getID());
		}
	}

	void GameNetworkServer::handleDeathMessage(DeathMessage& message, ENetPacket* packet)
	{
		ServerClient* client = getClient(message.getID());
		if (client) {
			sendToAllExcept((unsigned char*)packet->data, packet->dataLength, client->getID());
			client->removeLife();
			if (playersAlive() <= 1) {
				sendEndGameMessage();
			}
		}
	}
	
	int GameNetworkServer::playersAlive()
	{
		int alive = 0;
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			if (it->second->isAlive())
				alive++;
		}
		return alive;
	}
	
	string GameNetworkServer::findWinner()
	{
		string winner;
		map<int, ServerClient*>::iterator it;
		it = m_clients.begin();
		for ( ; it != m_clients.end(); it++) {
			if (it->second->isAlive()) {
				winner = it->second->getName();
				break;
			}
		}
		return winner;
	}
	
	void GameNetworkServer::sendEndGameMessage()
	{
		EndGameMessage message(m_clients.size(), findWinner());
		sendToAll(message);
	}
};

