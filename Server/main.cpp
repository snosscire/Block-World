#include "../Source/Engine/Network.h"

#include <enet/enet.h>

#include <iostream>
#include <map>

#include <signal.h>

using namespace std;
using namespace BadEngine;

bool keepRunning = true;
int lastClientID = 0;
map<int, ENetPeer*> clients;

void signalHandler(int signal) {
	cout << "Ctrl+c pressed. Shutting down server." << endl;
	keepRunning = false;
}

int main(int argc, char *argv[])
{
	enet_initialize();
	
	struct sigaction signalAction;
	signalAction.sa_handler = signalHandler;
	sigaction(SIGINT, &signalAction, NULL);
	
	ENetAddress address;
	ENetHost *server = NULL;
	
	address.host = ENET_HOST_ANY;
	address.port = 7788;
	
	server = enet_host_create(&address, 32, 0, 0, 0);
	if (server) {
		cout << "Starting BlockWorld server on port " << address.port << "." << endl;
		
		while (keepRunning) {
			ENetEvent event;
			
			if (enet_host_service(server, &event, 1)) {
				switch (event.type) {
					case ENET_EVENT_TYPE_NONE: {
						break;
					} case ENET_EVENT_TYPE_CONNECT: {
						cout << "Got new connection." << endl;
						int* nextClientID = new int();
						*nextClientID = lastClientID + 1;
						lastClientID = *nextClientID;
						clients.insert(pair<int, ENetPeer*>(*nextClientID, event.peer));
						event.peer->data = nextClientID;
						break;
					} case ENET_EVENT_TYPE_DISCONNECT: {
						cout << "Client disconnected." << endl;
						int* clientID = static_cast<int *>(event.peer->data);
						event.peer->data = NULL;
						clients.erase(*clientID);
						delete clientID;
						break;
					} case ENET_EVENT_TYPE_RECEIVE: {
						cout << "Received packet." << endl;
						const char* rawData = (char*)event.packet->data;
						string data = rawData;
						//int type = Network::readShortFromData(data);
						enet_packet_destroy(event.packet);
						break;
					}
				}
			}
		}
		
		enet_host_destroy(server);
	} else {
		cout << "Error: could not start server." << endl;
	}
	
	enet_deinitialize();
	
	return EXIT_SUCCESS;
}
