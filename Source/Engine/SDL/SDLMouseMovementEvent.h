#ifndef __BADENGINE_SDLMOUSEMOVEMENTEVENT_H__
#define __BADENGINE_SDLMOUSEMOVEMENTEVENT_H__

#include <SDL/SDL.h>

#include "../MouseMovementEvent.h"

namespace BadEngine {
	class SDLMouseMovementEvent : public MouseMovementEvent {
		private:
			SDL_Event* m_event;
		
		private:
			SDLMouseMovementEvent();
		
		public:
			SDLMouseMovementEvent(SDL_Event* event);
			~SDLMouseMovementEvent();
			unsigned int getX();
			unsigned int getY();
			int getRelativeX();
			int getRelativeY();
	};
};

#endif // __BADENGINE_SDLMOUSEMOVEMENTEVENT_H__
