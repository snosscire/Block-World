#include "GameNetwork.h"
#include "GameObject.h"

#include "Network/UpdateMessage.h"

#include "../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	GameNetwork::GameNetwork()
	{
	}
	
	GameNetwork::~GameNetwork()
	{
	}
		
	void GameNetwork::sendUpdate(ENetHost* host, ENetPeer* peer, GameObject& object)
	{
		UpdateMessage message(object.getNetworkID(), object.getX(), object.getY());
		string data = message.toData();
		Network::sendData(host, peer, data);
	}
};
