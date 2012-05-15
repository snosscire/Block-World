#include "../Game/GameNetworkServer.h"

#include <signal.h>

#include <iostream>

using namespace std;
using namespace BadEngine;
using namespace BlockWorld;

bool keepRunning = true;

void signalHandler(int signal) {
	cout << "Ctrl+c pressed. Shutting down server." << endl;
	keepRunning = false;
}

int main(int argc, char *argv[])
{
	enet_initialize();
	
	/*
	struct sigaction signalAction;
	signalAction.sa_handler = signalHandler;
	sigaction(SIGINT, &signalAction, NULL);
	*/
	
	signal(SIGINT, signalHandler);
	
	GameNetworkServer server;
	
	if (server.start(7788)) {
		cout << "Starting BlockWorld server on port 7788." << endl;
		
		while (keepRunning) {
			server.notifyObservers(1);
		}
		
		server.stop();
	} else {
		cout << "Error: could not start server." << endl;
	}
	
	enet_deinitialize();
	
	return EXIT_SUCCESS;
}

