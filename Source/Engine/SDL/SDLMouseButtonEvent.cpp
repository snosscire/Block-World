#include "SDLMouseButtonEvent.h"

namespace BadEngine {
	SDLMouseButtonEvent::SDLMouseButtonEvent() :
		MouseButtonEvent(),
		m_event(0)
	{
	}
	
	SDLMouseButtonEvent::SDLMouseButtonEvent(SDL_Event* event) :
		MouseButtonEvent(),
		m_event(event)
	{
	}
	
	SDLMouseButtonEvent::~SDLMouseButtonEvent()
	{
	}
	
	int SDLMouseButtonEvent::getX()
	{
		return m_event->button.x;
	}
	
	int SDLMouseButtonEvent::getY()
	{
		return m_event->button.x;
	}
	
	MouseButton SDLMouseButtonEvent::getButton()
	{
		return static_cast<MouseButton>(m_event->button.button);
	}
};
