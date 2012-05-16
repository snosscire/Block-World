#ifndef __BADENGINE_CONSOLE_H__
#define __BADENGINE_CONSOLE_H__

#include "EventObserver.h"

#include <map>
#include <string>

using namespace std;

namespace BadEngine {
	class BitmapFont;
	class Engine;
	class KeyboardButtonEvent;
	class ConsoleCommand;
	class Console : public EventObserver{
		private:
			bool m_active;
			BitmapFont* m_font;
			string m_currentCommand;
			map<string, ConsoleCommand*> m_commands;
		
		private:
			void processCurrentCommand();
			Console();
			
		public:
			Console(Engine& engine, BitmapFont& font);
			~Console();
			void registerCommand(string command, ConsoleCommand* action);
			void setActive(bool active);
			void activate();
			void deactivate();
			void draw(Engine& engine);
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif
