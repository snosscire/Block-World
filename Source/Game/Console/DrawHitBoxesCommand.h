#ifndef __BLOCKWORLD_DRAWHITBOXESCOMMAND_H__
#define __BLOCKWORLD_DRAWHITBOXESCOMMAND_H__

#include "../../Engine/ConsoleCommand.h"

using namespace BadEngine;

namespace BlockWorld {
	class Game;
	class DrawHitBoxesCommand : public ConsoleCommand {
		public:
			DrawHitBoxesCommand();
			virtual ~DrawHitBoxesCommand() { }
			void invoke(vector<string>& parameters);
	};
};

#endif
