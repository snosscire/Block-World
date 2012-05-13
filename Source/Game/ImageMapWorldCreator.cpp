#include "ImageMapWorldCreator.h"
#include "World.h"
#include "BlockType.h"
#include "Blocks/DefaultBlock.h"

#include <SDL/SDL_image.h>

#include <iostream>

using namespace std;

namespace BlockWorld {
	ImageMapWorldCreator::ImageMapWorldCreator()
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
	
	World* ImageMapWorldCreator::createWorld(Engine& engine, string& imagePath, string& xmlPath)
	{
		World* world = NULL;
		SDL_Surface* surface = IMG_Load(imagePath.c_str());
		if (surface) {
			Uint32 dirtColour = SDL_MapRGB(surface->format, 90, 40, 10);
			Uint32 grassColour = SDL_MapRGB(surface->format, 50, 100, 20);
			Uint32 nothingColour = SDL_MapRGB(surface->format, 255, 255, 255);
			
			world = new World(surface->w, surface->h);
			
			for (int x = 0; x < surface->w; x++) {
				for (int y = 0; y < surface->h; y++) {
					Uint32 pixelColour = getPixel(surface, x, y);
					if( pixelColour == dirtColour ) {
						//cout << "Found dirt." << endl;
						Image* image = engine.loadImage("Resources/Blocks/dirt.png");
						DefaultBlock* block = new DefaultBlock(*world, x, y, BLOCK_TYPE_DIRT, *image);
						world->setBlock(x, y, block);
					} else if (pixelColour == grassColour ) {
						//cout << "Found grass." << endl;
						Image* image = engine.loadImage("Resources/Blocks/grass.png");
						DefaultBlock* block = new DefaultBlock(*world, x, y, BLOCK_TYPE_GRASS, *image);
						world->setBlock(x, y, block);
					} else if (pixelColour == nothingColour) {
						//cout << "Found nothing." << endl;
					} else {
						//cout << "Found absolutely nothing." << endl;
					}
				}
			}
			
			SDL_FreeSurface(surface);
		}
		return world;
	}
};
