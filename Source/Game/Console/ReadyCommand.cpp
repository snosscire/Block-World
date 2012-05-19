#include "ReadyCommand.h"

#include "../NetworkTestMode.h"

#include <list>
#include <iostream>

using namespace std;

namespace BlockWorld {
	ReadyCommand::ReadyCommand(NetworkTestMode& mode) :
		ConsoleCommand(),
		m_gameMode(&mode)
	{
	}
	
	void ReadyCommand::invoke(vector<string>& parameters) {
		cout << "Invoking ready command." << endl;
		m_gameMode->sendReadyMessage();
	}
};

