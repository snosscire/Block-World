#include "StartGameMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	StartGameMessage::StartGameMessage() :
		NetworkMessage()
	{
	}
	
	StartGameMessage::StartGameMessage(string& data) :
		NetworkMessage()
	{
	}
	
	StartGameMessage::~StartGameMessage()
	{
	}
	
	string StartGameMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_START_GAME);
		return data;
	}
};

