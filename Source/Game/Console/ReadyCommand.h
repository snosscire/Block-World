#ifndef __BLOCKWORLD_READYCOMMAND_H__
#define __BLOCKWORLD_READYCOMMAND_H__

#include "../../Engine/ConsoleCommand.h"

using namespace BadEngine;

namespace BlockWorld {
	class NetworkTestMode;
	class ReadyCommand : public ConsoleCommand {
		private:
			NetworkTestMode* m_gameMode;
		
		public:
			ReadyCommand(NetworkTestMode& game);
			virtual ~ReadyCommand() { }
			void invoke(vector<string>& parameters);
	};
};

#endif
