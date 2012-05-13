#ifndef __BADENGINE_SDLVIDEORESIZEEVENT_H__
#define __BADENGINE_SDLVIDEORESIZEEVENT_H__

#include <SDL/SDL.h>

#include "../VideoResizeEvent.h"

namespace BadEngine {
	class SDLVideoResizeEvent : public VideoResizeEvent {
		private:
			SDL_Event* m_event;
		
		private:
			SDLVideoResizeEvent();
		
		public:
			SDLVideoResizeEvent(SDL_Event* event);
			~SDLVideoResizeEvent();
			int getWidth();
			int getHeight();
	};
};

#endif // __BADENGINE_SDLVIDEORESIZEEVENT_H__
