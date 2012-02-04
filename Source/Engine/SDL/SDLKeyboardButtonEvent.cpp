#include "SDLKeyboardButtonEvent.h"

namespace BadEngine {
	SDLKeyboardButtonEvent::SDLKeyboardButtonEvent() :
		KeyboardButtonEvent(),
		m_event(0)
	{
	}
	
	SDLKeyboardButtonEvent::SDLKeyboardButtonEvent(SDL_Event* event) :
		KeyboardButtonEvent(),
		m_event(event)
	{
	}
	
	SDLKeyboardButtonEvent::~SDLKeyboardButtonEvent()
	{
	}
	
	KeyboardButton SDLKeyboardButtonEvent::getButton()
	{
		// The KeyboardButton enum has been made to exactly copy
		// the SDL_keysym enum in SDL.
		return static_cast<KeyboardButton>(m_event->key.keysym.sym);
	}
};
