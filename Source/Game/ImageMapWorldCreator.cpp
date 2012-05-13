#include "ImageMapWorldCreator.h"
#include "World.h"
#include "WorldBackground.h"
#include "MapDirectory.h"
#include "BlockType.h"
#include "Blocks/DefaultBlock.h"

#include <SDL/SDL_image.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace BlockWorld {
	ImageMapWorldCreator::ImageMapWorldCreator() :
		m_textures()
	{
	}
		
	ImageMapWorldCreator::~ImageMapWorldCreator()
	{
	}
	
	Uint32 ImageMapWorldCreator::getPixel(SDL_Surface* surface, int x, int y) {
		int bpp = surface->format->BytesPerPixel;
		/* Here p is the address to the pixel we want to retrieve */
		Uint8 *p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
		switch(bpp) {
			case 1:
				return *p;
			case 2:
				return *(Uint16 *)p;
			case 3:
				if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
					return p[0] << 16 | p[1] << 8 | p[2];
				} else {
					return p[0] | p[1] << 8 | p[2] << 16;
				}
			case 4:
				return *(Uint32 *)p;
			default:
				return 0; /* shouldn't happen, but avoids warnings */
		}
	}
	
	void ImageMapWorldCreator::readBackgroundsElement(XMLElement* containerElement, Engine* engine, MapDirectory* mapDirectory, World* world)
	{
		XMLElement* backgroundElement = containerElement->FirstChildElement("background");
		
		while (backgroundElement) {
			bool error = false;
			const char* imageName = NULL;
			int layer;
			int x;
			int y;
			double speed;
			
			if (backgroundElement->QueryIntAttribute("layer", &layer) != XML_NO_ERROR) {
				error = true;
			}
			if (backgroundElement->QueryIntAttribute("x", &x) != XML_NO_ERROR) {
				error = true;
			}
			if (backgroundElement->QueryIntAttribute("y", &y) != XML_NO_ERROR) {
				error = true;
			}
			if (backgroundElement->QueryDoubleAttribute("speed", &speed) != XML_NO_ERROR) {
				error = true;
			}
			
			imageName = backgroundElement->Attribute("image");
			if (!imageName) {
				error = true;
			}
			
			if (!error) {
				ostringstream imagePath;
				imagePath << mapDirectory->getPath() << "/Backgrounds/" << imageName;
				Image* image = engine->loadImage(imagePath.str());
				if (image) {
					world->addBackground(new WorldBackground(layer, x, y, speed, *image));
				}
			}
			
			backgroundElement = backgroundElement->NextSiblingElement("background");
		}
	}
	
	void ImageMapWorldCreator::readTexturesElement(XMLElement* containerElement, SDL_Surface* surface)
	{
		XMLElement* textureElement = containerElement->FirstChildElement("texture");
		
		while (textureElement) {
			bool error = false;
			const char* image = NULL;
			int red;
			int green;
			int blue;
			
			if (textureElement->QueryIntAttribute("red", &red) != XML_NO_ERROR) {
				error = true;
			}
			if (textureElement->QueryIntAttribute("green", &green) != XML_NO_ERROR) {
				error = true;
			}
			if (textureElement->QueryIntAttribute("blue", &blue) != XML_NO_ERROR) {
				error = true;
			}
			
			image = textureElement->Attribute("image");
			if (!image) {
				error = true;
			}
			
			if (!error) {
				cout << "Red: " << red << ", green: " << green << ", blue: " << blue << ", image: " << image << endl;
				Uint32 color = SDL_MapRGB(surface->format, red, green, blue);
				string name = image;
				m_textures.insert(pair<Uint32, string>(color, name));
			}
			
			textureElement = textureElement->NextSiblingElement("texture");
		}
	}
	
	void ImageMapWorldCreator::readXML(MapDirectory* mapDirectory, Engine* engine, SDL_Surface* surface, World* world)
	{
		XMLDocument document;
		if (document.LoadFile(mapDirectory->getXMLPath().c_str()) == XML_NO_ERROR) {
			XMLElement* mapElement = document.FirstChildElement("map");
			if (mapElement) {
				XMLElement* backgroundsElement = mapElement->FirstChildElement("backgrounds");
				XMLElement* texturesElement = mapElement->FirstChildElement("textures");
				if (texturesElement) {
					readTexturesElement(texturesElement, surface);
				}
				if (backgroundsElement) {
					readBackgroundsElement(backgroundsElement, engine, mapDirectory, world);
				}
			}
		} else {
			cout << document.GetErrorStr1() << endl;
			cout << document.GetErrorStr2() << endl;
		}
	}
	
	World* ImageMapWorldCreator::createWorld(Engine& engine, MapDirectory& mapDirectory)
	{
		World* world = NULL;
		SDL_Surface* surface = IMG_Load(mapDirectory.getImagePath().c_str());
		if (surface) {
			world = new World(surface->w, surface->h);
			
			if (mapDirectory.hasXML()) {
				readXML(&mapDirectory, &engine, surface, world);
			}
			
			for (int x = 0; x < surface->w; x++) {
				for (int y = 0; y < surface->h; y++) {
					Uint32 color = getPixel(surface, x, y);
					
					map<Uint32, string>::iterator it;
					it = m_textures.find(color);
					
					if (it != m_textures.end()) {
						ostringstream texturePath;
						texturePath << mapDirectory.getPath() << "/Blocks/" << it->second;
						Image* image = engine.loadImage(texturePath.str());
						if (image) {
							DefaultBlock* block = new DefaultBlock(*world, x, y, BLOCK_TYPE_DIRT, *image);
							world->setBlock(x, y, block);
						}
					}
				}
			}
			
			SDL_FreeSurface(surface);
		}
		return world;
	}
};
