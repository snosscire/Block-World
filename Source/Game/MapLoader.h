#ifndef __BLOCKWORLD_MAPLOADER_H__
#define __BLOCKWORLD_MAPLOADER_H__

#include <list>
#include <string>

using namespace std;

namespace BlockWorld {
	class MapDirectory;
	class MapLoader {
		private:
			list<MapDirectory*> m_maps;
		
		public:
			MapLoader();
			virtual ~MapLoader();
			void loadDirectory(string path);
			list<MapDirectory*>& getMaps();
	};
};

#endif // __BLOCKWORLD_MAPLOADER_H__
