#include "MapCommand.h"

#include "../BlockWorld.h"
#include "../Game.h"
#include "../GameMode.h"
#include "../MapLoader.h"
#include "../MapDirectory.h"
#include "../TestMode.h"

#include <list>
#include <iostream>

using namespace std;

namespace BlockWorld {
	MapCommand::MapCommand(Game& game) :
		ConsoleCommand(),
		m_game(&game)
	{
	}
	
	void MapCommand::invoke(vector<string>& parameters) {
		cout << "Map command." << endl;
		if (parameters.size() > 0) {
			TestMode* mode = dynamic_cast<TestMode*>(m_game->getMode(BlockWorld::TEST_MODE));
			if (mode) {
				cout << "Found mode." << endl;
				MapLoader* loader = new MapLoader();
				MapDirectory* map = NULL;
				
				loader->loadDirectory("Resources/Maps");
				
				list<MapDirectory*>& maps = loader->getMaps();
				list<MapDirectory*>::iterator it = maps.begin();
				
				for ( ; it != maps.end(); it++) {
					cout << "Map: " << (*it)->getDirectoryName() << " (" << parameters[0] << ")" << endl;
					if ((*it)->getDirectoryName().compare(parameters[0]) == 0) {
						map = *it;
						break;
					}
				}
				
				if (map) {
					cout << "Found map." << endl;
					mode->setMap(map);
					m_game->setCurrentMode(BlockWorld::TEST_MODE);
				}
				
				delete loader;
			}
		}
	}
};

