#include "LoadMapMessage.h"

#include "../GameNetwork.h"
#include "../../Engine/Network.h"

using namespace BadEngine;

namespace BlockWorld {
	LoadMapMessage::LoadMapMessage() :
		NetworkMessage(),
		m_players(0),
		m_name()
	{
	}
	
	LoadMapMessage::LoadMapMessage(int players, string name) :
		NetworkMessage(),
		m_players(players),
		m_name(name)
	{
	}
	
	LoadMapMessage::LoadMapMessage(string& data) :
		NetworkMessage(),
		m_players(0),
		m_name()
	{
		m_players = Network::readByteFromData(data);
		Network::readStringFromData(data, m_name);
	}
	
	LoadMapMessage::~LoadMapMessage()
	{
	}
	
	int LoadMapMessage::getPlayers()
	{
		return m_players;
	}
	
	string LoadMapMessage::getName()
	{
		return m_name;
	}
	
	string LoadMapMessage::toData()
	{
		string data;
		Network::addByteToData(data, GameNetwork::MESSAGE_LOAD_MAP);
		Network::addByteToData(data, m_players);
		Network::addStringToData(data, m_name);
		return data;
	}
};
