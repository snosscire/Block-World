#ifndef __GAME_H__
#define __GAME_H__

#include <map>
#include <string>

#include "Engine/Engine.h"

class GameMode;

using namespace std;
using namespace BadEngine;

class Game : public EventObserver {
	private:
		bool m_running;
		Engine* m_engine;
		map<const string, GameMode*> m_gameModes;
		GameMode* m_currentMode;
	
	private:
		Game();
	
	public:
		Game(Engine* engine);
		~Game();
		Engine *getEngine();
		void registerMode(const string& name, GameMode* mode);
		void setCurrentMode(const string& mode);
		void run(const string& mode);
		void quit();
		void onQuit();
};

#endif // __GAME_H__