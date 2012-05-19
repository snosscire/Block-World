#ifndef __BLOCKWORLD_GAME_H__
#define __BLOCKWORLD_GAME_H__

#include <map>
#include <string>

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"
#include "../Engine/Console.h"

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class GameMode;
	class GameNetworkClient;
	class Game : public EventObserver {
		private:
			bool m_running;
			Engine* m_engine;
			map<const string, GameMode*> m_gameModes;
			GameMode* m_currentMode;
			GameNetworkClient* m_network;
			bool m_showConsole;
			Console* m_console;
		
		private:
			Game();
		
		public:
			Game(Engine* engine);
			~Game();
			Engine *getEngine();
			GameNetworkClient* getNetwork();
			void registerMode(const string& name, GameMode* mode);
			void setCurrentMode(const string& mode);
			GameMode* getMode(const string& mode);
			Console* getConsole();
			void activateNetwork();
			void run(const string& mode);
			void quit();
			void onQuit();
			void onVideoResize(VideoResizeEvent& event);
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif // __BLOCKWORLD_GAME_H__
