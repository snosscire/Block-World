#ifndef __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
#define __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__

#include <string>

using namespace std;

namespace BlockWorld {
	class World;
	class ImageMapWorldCreator {
		public:
			ImageMapWorldCreator();
			virtual ~ImageMapWorldCreator();
			World* createWorld(string& xmlPath, string& imagePath);
	};
};

#endif // __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
