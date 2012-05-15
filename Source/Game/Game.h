#ifndef __BLOCKWORLD_GAME_H__
#define __BLOCKWORLD_GAME_H__

#include <map>
#include <string>

#include "../Engine/Engine.h"
#include "../Engine/EventObserver.h"

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
		
		private:
			Game();
		
		public:
			Game(Engine* engine);
			~Game();
			Engine *getEngine();
			GameNetworkClient* getNetwork();
			void registerMode(const string& name, GameMode* mode);
			void setCurrentMode(const string& mode);
			void activateNetwork();
			void run(const string& mode);
			void quit();
			void onQuit();
			void onVideoResize(VideoResizeEvent& event);
	};
};

#endif // __BLOCKWORLD_GAME_H__
