#include "SDLVideoResizeEvent.h"

namespace BadEngine {
	SDLVideoResizeEvent::SDLVideoResizeEvent() :
		VideoResizeEvent(),
		m_event(NULL)
	{
	}
	
	SDLVideoResizeEvent::SDLVideoResizeEvent(SDL_Event* event) :
		VideoResizeEvent(),
		m_event(event)
	{
	}
	
	SDLVideoResizeEvent::~SDLVideoResizeEvent()
	{
	}
	
	int SDLVideoResizeEvent::getWidth()
	{
		return m_event->resize.w;
	}
	
	int SDLVideoResizeEvent::getHeight()
	{
		return m_event->resize.h;
	}
};
