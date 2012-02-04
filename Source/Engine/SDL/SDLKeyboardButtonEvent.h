#ifndef __SDLKEYBOARDBUTTONEVENT_H__
#define __SDLKEYBOARDBUTTONEVENT_H__

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
			~SDLKeyboardButtonEvent();
			KeyboardButton getButton();
	};
};

#endif // __SDLKEYBOARDBUTTONEVENT_H__
