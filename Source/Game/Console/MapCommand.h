#ifndef __BLOCKWORLD_MAPCOMMAND_H__
#define __BLOCKWORLD_MAPCOMMAND_H__

#include "../../Engine/ConsoleCommand.h"

using namespace BadEngine;

namespace BlockWorld {
	class Game;
	class MapCommand : public ConsoleCommand {
		private:
			Game* m_game;
		
		public:
			MapCommand(Game& game);
			virtual ~MapCommand() { }
			void invoke(vector<string>& parameters);
	};
};

#endif
