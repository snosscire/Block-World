#ifndef __BADENGINE_SDLENGINE_H__
#define __BADENGINE_SDLENGINE_H__

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
			void drawRectangle(Rectangle& rectangle, int red, int green, int blue);
			int getRandomNumber(int min, int max);
			int getScreenWidth();
			int getScreenHeight();
			int getCurrentTime();
	};
};

#endif // __BADENGINE_SDLENGINE_H__
