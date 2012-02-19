#ifndef __BADENGINE_SDLMOUSEBUTTONEVENT_H__
#define __BADENGINE_SDLMOUSEBUTTONEVENT_H__

#include <SDL/SDL.h>

#include "../MouseButtonEvent.h"

namespace BadEngine {
	class SDLMouseButtonEvent : public MouseButtonEvent {
		private:
			SDL_Event* m_event;
		
		private:
			SDLMouseButtonEvent();
		
		public:
			SDLMouseButtonEvent(SDL_Event* event);
			~SDLMouseButtonEvent();
			int getX();
			int getY();
			MouseButton getButton();
	};
};

#endif // __BADENGINE_SDLMOUSEBUTTONEVENT_H__
