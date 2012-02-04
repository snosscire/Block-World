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
	};
};

#endif // __SDLENGINE_H__
