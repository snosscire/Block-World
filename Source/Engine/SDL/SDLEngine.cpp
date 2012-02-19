#include "SDLEngine.h"
#include "SDLKeyboardButtonEvent.h"
#include "SDLMouseMovementEvent.h"
#include "SDLMouseButtonEvent.h"

#include "../Rectangle.h"

#include <stdlib.h>
#include <time.h>

namespace BadEngine
{
	SDLEngine::SDLEngine() :
		Engine(),
		m_videoSurface(0)
	{
	}
	
	SDLEngine::~SDLEngine()
	{
	}
	
	void SDLEngine::start()
	{
		Uint32 flags = 0;
		SDL_Init(SDL_INIT_VIDEO);
		flags |= SDL_HWPALETTE;
		flags |= SDL_HWSURFACE;
		flags |= SDL_HWACCEL;
		flags |= SDL_DOUBLEBUF;
		m_videoSurface = SDL_SetVideoMode(640, 480, 0, flags);
		srand(time(NULL));
	}
	
	void SDLEngine::stop()
	{
		SDL_Quit();
	}
	
	void SDLEngine::notifyEventObservers()
	{
		SDL_Event event;
		EventType type;
		SDLKeyboardButtonEvent keyboardButtonEvent(&event);
		SDLMouseButtonEvent mouseButtonEvent(&event);
		SDLMouseMovementEvent mouseMovementEvent(&event);
		list<EventObserver*>::iterator it;
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:            type = EVENT_QUIT; break;
				case SDL_KEYDOWN:         type = EVENT_KEYBOARD_BUTTON_DOWN; break;
				case SDL_KEYUP:           type = EVENT_KEYBOARD_BUTTON_UP; break;
				case SDL_MOUSEBUTTONDOWN: type = EVENT_MOUSE_BUTTON_DOWN; break;
				case SDL_MOUSEBUTTONUP:   type = EVENT_MOUSE_BUTTON_UP; break;
				case SDL_MOUSEMOTION:     type = EVENT_MOUSE_MOVEMENT; break;
				default:                  type = EVENT_NONE; break;
			}
			
			it = m_eventObservers[type].begin();
			for ( ; it != m_eventObservers[type].end(); it++) {
				switch (type) {
					case EVENT_QUIT:                 (*it)->onQuit(); break;
					case EVENT_KEYBOARD_BUTTON_DOWN: (*it)->onKeyboardButtonDown(keyboardButtonEvent); break;
					case EVENT_KEYBOARD_BUTTON_UP:   (*it)->onKeyboardButtonUp(keyboardButtonEvent); break;
					case EVENT_MOUSE_BUTTON_DOWN:    (*it)->onMouseButtonDown(mouseButtonEvent); break;
					case EVENT_MOUSE_BUTTON_UP:      (*it)->onMouseButtonUp(mouseButtonEvent); break;
					case EVENT_MOUSE_MOVEMENT:       (*it)->onMouseMovement(mouseMovementEvent); break;
					default: break;
				}
			}
			
		}
	}
	
	void SDLEngine::clearScreen()
	{
		Uint32 black = SDL_MapRGB(m_videoSurface->format, 0, 0, 0);
		SDL_FillRect(m_videoSurface, NULL, black);
	}
	
	void SDLEngine::updateScreen()
	{
		SDL_Flip(m_videoSurface);
	}
	
	void SDLEngine::drawRectangle(Rectangle& rectangle, int red, int green, int blue)
	{
		SDL_Rect rect;
		rect.x = rectangle.getX();
		rect.y = rectangle.getY();
		rect.w = rectangle.getWidth();
		rect.h = rectangle.getHeight();
		
		Uint32 color = SDL_MapRGB(m_videoSurface->format, red, green, blue);
		
		SDL_FillRect(m_videoSurface, &rect, color);
	}
	
	int SDLEngine::getRandomNumber(int min, int max)
	{
		return (rand() % (max - min + 1) + min);
	}
	
	int SDLEngine::getScreenWidth()
	{
		return m_videoSurface->w;
	}
	
	int SDLEngine::getScreenHeight()
	{
		return m_videoSurface->h;
	}
	
	double SDLEngine::getCurrentTime()
	{
		return SDL_GetTicks();
	}
};
