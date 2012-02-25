#ifndef __BADENGINE_SDLKEYBOARDBUTTONEVENT_H__
#define __BADENGINE_SDLKEYBOARDBUTTONEVENT_H__

#include <SDL/SDL.h>

#include "../KeyboardButtonEvent.h"

namespace BadEngine {
	class SDLKeyboardButtonEvent : public KeyboardButtonEvent {
		private:
			SDL_Event* m_event;
		
		private:
			SDLKeyboardButtonEvent();
		
		public:
			SDLKeyboardButtonEvent(SDL_Event* event);
			virtual ~SDLKeyboardButtonEvent();
			KeyboardButton getButton();
	};
};

#endif // __BADENGINE_SDLKEYBOARDBUTTONEVENT_H__
