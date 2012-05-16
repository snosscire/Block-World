#ifndef __BADENGINE_CONSOLECOMMAND_H__
#define __BADENGINE_CONSOLECOMMAND_H__

#include <vector>
#include <string>

using namespace std;

namespace BadEngine {
	class ConsoleCommand {
		protected:
			ConsoleCommand() { }
		
		public:
			virtual ~ConsoleCommand() { }
			virtual void invoke(vector<string>& parameters) = 0;
	};
};

#endif
