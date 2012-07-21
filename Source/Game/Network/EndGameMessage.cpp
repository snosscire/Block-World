#include "EndGameMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	EndGameMessage::EndGameMessage(int players, string winner) :
		NetworkMessage(),
		m_players(players),
		m_winner(winner)
	{
	}
	
	EndGameMessage::EndGameMessage(string& data) :
		NetworkMessage()
	{
		m_players = Network::readByteFromData(data);
		Network::readStringFromData(data, m_winner);
	}
	
	EndGameMessage::~EndGameMessage()
	{
	}
	
	string EndGameMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_END_GAME);
		Network::addByteToData(data, m_players);
		Network::addStringToData(data, m_winner);
		return data;
	}
	
	int EndGameMessage::getPlayers()
	{
		return m_players;
	}
	
	string EndGameMessage::getWinner()
	{
		return m_winner;
	}
};

