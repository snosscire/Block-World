#ifndef __BLOCKWORLD_QUITCOMMAND_H__
#define __BLOCKWORLD_QUITCOMMAND_H__

#include "../../Engine/ConsoleCommand.h"

using namespace BadEngine;

namespace BlockWorld {
	class Game;
	class QuitCommand : public ConsoleCommand {
		private:
			Game* m_game;
		
		public:
			QuitCommand(Game& game);
			virtual ~QuitCommand() { }
			void invoke(vector<string>& parameters);
	};
};

#endif
