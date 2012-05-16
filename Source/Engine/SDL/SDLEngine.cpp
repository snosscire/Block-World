#include "SDLEngine.h"
#include "SDLVideoResizeEvent.h"
#include "SDLKeyboardButtonEvent.h"
#include "SDLMouseMovementEvent.h"
#include "SDLMouseButtonEvent.h"
#include "SDLImage.h"

#include "../Square.h"
#include "../BitmapFont.h"

#include <stdlib.h>
#include <time.h>

#include <iostream>

#include <SDL/SDL_image.h>

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
		SDL_Init(SDL_INIT_VIDEO);
		setVideoMode(640, 480);
		srand(time(NULL));
		SDL_ShowCursor(SDL_DISABLE);
	}
	
	void SDLEngine::stop()
	{
		SDL_Quit();
	}
	
	void SDLEngine::setVideoMode(int width, int height)
	{
		Uint32 flags = 0;
		flags |= SDL_HWPALETTE;
		flags |= SDL_HWSURFACE;
		flags |= SDL_HWACCEL;
		flags |= SDL_DOUBLEBUF;
		flags |= SDL_RESIZABLE;
		m_videoSurface = SDL_SetVideoMode(width, height, 0, flags);
	}
	
	void SDLEngine::notifyEventObservers()
	{
		SDL_Event event;
		EventType type;
		SDLVideoResizeEvent videoResizeEvent(&event);
		SDLKeyboardButtonEvent keyboardButtonEvent(&event);
		SDLMouseButtonEvent mouseButtonEvent(&event);
		SDLMouseMovementEvent mouseMovementEvent(&event);
		list<EventObserver*>::iterator it;
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:            type = EVENT_QUIT; break;
				case SDL_VIDEORESIZE:     type = EVENT_VIDEO_RESIZE; break;
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
					case EVENT_VIDEO_RESIZE:         (*it)->onVideoResize(videoResizeEvent); break;
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
	
	void SDLEngine::drawSquare(Square& rectangle, int red, int green, int blue)
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
	
	Image* SDLEngine::loadImage(string filename)
	{
		SDL_Surface* surface = IMG_Load(filename.c_str());
		if (surface) {
			SDL_Surface* newSurface = SDL_DisplayFormatAlpha(surface);
			if (newSurface) {
				SDL_FreeSurface(surface);
				surface = newSurface;
			}
			return new SDLImage(surface, *this);
		} else {
			std::cout << "Failed to load image: " << filename << std::endl;
		}
		return NULL;
	}
	
	BitmapFont* SDLEngine::loadBitmapFont(string filename, int width, int height)
	{
		return new BitmapFont(*this, filename, width, height);
	}
	
	void SDLEngine::drawSurface(SDL_Surface* surface, int x, int y)
	{
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		SDL_BlitSurface(surface, NULL, m_videoSurface, &dst);
	}
	
	SDL_Surface* SDLEngine::getVideoSurface()
	{
		return m_videoSurface;
	}
	
	void SDLEngine::grabInput()
	{
		SDL_WM_GrabInput(SDL_GRAB_ON);
	}
	
	void SDLEngine::releaseInput()
	{
		SDL_WM_GrabInput(SDL_GRAB_OFF);
	}
};
