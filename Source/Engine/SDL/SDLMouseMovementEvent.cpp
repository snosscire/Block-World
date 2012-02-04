#include "SDLMouseMovementEvent.h"

namespace BadEngine {
	SDLMouseMovementEvent::SDLMouseMovementEvent() :
		MouseMovementEvent(),
		m_event(0)
	{
	}
	
	SDLMouseMovementEvent::SDLMouseMovementEvent(SDL_Event* event) :
		MouseMovementEvent(),
		m_event(event)
	{
	}
	
	SDLMouseMovementEvent::~SDLMouseMovementEvent()
	{
	}
	
	unsigned int SDLMouseMovementEvent::getX()
	{
		return m_event->motion.x;
	}
	
	unsigned int SDLMouseMovementEvent::getY()
	{
		return m_event->motion.y;
	}
	
	int SDLMouseMovementEvent::getRelativeX()
	{
		return m_event->motion.xrel;
	}
	
	int SDLMouseMovementEvent::getRelativeY()
	{
		return m_event->motion.yrel;
	}
};
