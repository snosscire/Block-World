#include "QuitCommand.h"

#include "../Game.h"

namespace BlockWorld {
	QuitCommand::QuitCommand(Game& game) :
		ConsoleCommand(),
		m_game(&game)
	{
	}
	
	void QuitCommand::invoke(vector<string>& parameters) {
		m_game->quit();
	}
};

