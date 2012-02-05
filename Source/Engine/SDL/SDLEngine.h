#ifndef __SDLENGINE_H__
#define __SDLENGINE_H__

#include <SDL/SDL.h>

#include "../Engine.h"

namespace BadEngine {
	class SDLEngine : public Engine {
		private:
			SDL_Surface* m_videoSurface;
		
		public:
			SDLEngine();
			~SDLEngine();
			void start();
			void stop();
			void notifyEventObservers();
			void clearScreen();
			void updateScreen();
			void drawRectangle(Rectangle& rectangle, unsigned int red, unsigned int green, unsigned int blue);
			int getRandomNumber(int min, int max);
			unsigned int getScreenWidth();
			unsigned int getScreenHeight();
	};
};

#endif // __SDLENGINE_H__
