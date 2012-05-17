#ifndef __BADENGINE_SDLIMAGE_H__
#define __BADENGINE_SDLIMAGE_H__

#include "../Image.h"

#include <SDL/SDL.h>

namespace BadEngine {
	class SDLEngine;
	class SDLImage : public Image {
		private:
			SDL_Surface* m_surface;
			SDLEngine* m_engine;
		
		private:
			SDLImage();
		
		public:
			SDLImage(SDL_Surface* surface, SDLEngine& engine);
			virtual ~SDLImage();
			SDL_Surface* getSurface();
			void draw(int x, int y);
			int getWidth();
			int getHeight();
			void flip();
			void rotate(double angle);
	};
};

#endif // __BADENGINE_SDLIMAGE_H__
