#ifndef __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
#define __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__

#include "../Engine/Engine.h"

#include <SDL/SDL.h>

#include <string>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class World;
	class ImageMapWorldCreator {
		private:
			Uint32 getPixel(SDL_Surface* surface, int x, int y);
		
		public:
			ImageMapWorldCreator();
			virtual ~ImageMapWorldCreator();
			World* createWorld(Engine& engine, string& imagePath, string& xmlPath);
	};
};

#endif // __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
