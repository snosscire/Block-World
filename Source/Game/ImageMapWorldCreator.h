#ifndef __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
#define __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__

#include "../Engine/Engine.h"

#include "../External/tinyxml2/tinyxml2.h"

#include <SDL/SDL.h>

#include <map>
#include <string>

using namespace std;
using namespace tinyxml2;
using namespace BadEngine;

namespace BlockWorld {
	class MapDirectory;
	class World;
	class ImageMapWorldCreator {
		private:
			map<Uint32, string> m_textures;
		
		private:
			Uint32 getPixel(SDL_Surface* surface, int x, int y);
			void readBackgroundsElement(XMLElement* containerElement, Engine* engine, MapDirectory* mapDirectory, World* world);
			void readTexturesElement(XMLElement* containerElement, SDL_Surface* surface);
			void readXML(MapDirectory* mapDirectory, Engine* engine, SDL_Surface* surface, World* world);
		
		public:
			ImageMapWorldCreator();
			virtual ~ImageMapWorldCreator();
			World* createWorld(Engine& engine, MapDirectory& mapDirectory);
	};
};

#endif // __BLOCKWORLD_IMAGEMAPWORLDCREATOR_H__
