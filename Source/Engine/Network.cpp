#include "Network.h"
#include "NetworkObserver.h"

#include <cmath>

#include <iostream>

namespace BadEngine {
	long Network::byteToNumber(unsigned char byte)
	{
		long number = 0 + byte;
		return number;
	}
	
	void Network::addByteToData(string& data, int value)
	{
		data += (unsigned char)value;
	}
	
	void Network::addShortToData(string& data, int value)
	{
		data += (unsigned char)(value & 0xFF);
		data += (unsigned char)((value >> 8) & 0xFF);
	}
	
	void Network::addLongToData(string& data, int value)
	{
		data += (unsigned char)(value & 0xFF);
		data += (unsigned char)((value >> 8) & 0xFF);
		data += (unsigned char)((value >> 16) & 0xFF);
		data += (unsigned char)((value >> 24) & 0xFF);
	}
	
	void Network::addDoubleToData(string& data, double value)
	{
		double temp = floor(value * 10000.0);
		long number = (temp > 0.0) ? floor(temp + 0.5) : ceil(temp - 0.5);
		addLongToData(data, number);
	}
	
	void Network::addStringToData(string& data, string value)
	{
		addLongToData(data, value.length());
		data += value;
	}
	
	int Network::readByteFromData(string& data)
	{
		int value = 0;
		value |= byteToNumber(data[0]);
		if (data.length() > 1 ) {
			data.replace(0, 1, "");
		}
		return value;
	}
	
	int Network::readShortFromData(string& data)
	{
		int value = 0;
		value |= byteToNumber(data[0]);
		value |= byteToNumber(data[1]) << 8;
		if (data.length() > 2 ) {
			data.replace(0, 2, "");
		}
		return value;
	}
	
	int Network::readLongFromData(string& data)
	{
		int value = 0;
		value |= byteToNumber(data[0]);
		value |= byteToNumber(data[1]) << 8;
		value |= byteToNumber(data[2]) << 16;
		value |= byteToNumber(data[3]) << 24;
		if (data.length() > 4 ) {
			data.replace(0, 4, "");
		}
		return value;
	}
	
	double Network::readDoubleFromData(string& data)
	{
		long number = readLongFromData(data);
		double value = number / 10000.0;
		return value;
	}
	
	void Network::readStringFromData(string& data, string& content)
	{
		unsigned long length = readLongFromData(data);
		content = data.substr(0, length);
		if (data.length() > length) {
			data.replace(0, length, "");
		}
	}
	
	void Network::sendData(ENetHost* host, ENetPeer* peer, string& data)
	{
		ENetPacket* packet = enet_packet_create(data.c_str(), data.length(), /*ENET_PACKET_FLAG_NO_ALLOCATE |*/ ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		enet_host_flush(host);
	}
	
	void Network::sendData(ENetHost* host, ENetPeer* peer, unsigned char* data, unsigned int length)
	{
		ENetPacket* packet = enet_packet_create(data, length, /*ENET_PACKET_FLAG_NO_ALLOCATE |*/ ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		enet_host_flush(host);
	}
	
	Network::Network() :
		m_observers(),
		m_host(NULL)
	{
	}
	
	Network::~Network()
	{
		if (m_host) {
			enet_host_flush(m_host);
			enet_host_destroy(m_host);
		}
	}
	
	void Network::notifyObservers(int timeout)
	{
		if (m_host) {
			ENetEvent event;
			bool receivedPacket = false;
			
			if (enet_host_service(m_host, &event, timeout)) {
				list<NetworkObserver*>::iterator it = m_observers.begin();
				for ( ; it != m_observers.end(); it++) {
					switch (event.type) {
						case ENET_EVENT_TYPE_NONE:       break;
						case ENET_EVENT_TYPE_CONNECT:    (*it)->onConnect(event.peer); break;
						case ENET_EVENT_TYPE_DISCONNECT: (*it)->onDisconnect(event.peer); break;
						case ENET_EVENT_TYPE_RECEIVE:    (*it)->onReceive(event.packet); receivedPacket = true; break;
					}
				}
			}
			
			if (receivedPacket) {
				enet_packet_destroy(event.packet);
				event.packet = NULL;
			}
		}
	}
	
	void Network::registerObserver(NetworkObserver* observer)
	{
		m_observers.push_back(observer);
	}
	
	void Network::unregisterObserver(NetworkObserver* observer)
	{
		bool found;
		list<NetworkObserver*>::iterator it = m_observers.begin();
		for ( ; it != m_observers.end(); it++) {
			if ((*it) == observer) {
				found = true;
				break;
			}
		}
		if (found) {
			m_observers.erase(it);
		}
	}
};

