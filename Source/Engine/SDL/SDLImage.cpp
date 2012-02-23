#include "SDLImage.h"
#include "SDLEngine.h"

#include <iostream>

namespace BadEngine {
	SDLImage::SDLImage() :
		Image(),
		m_surface(NULL),
		m_engine(NULL)
	{
	}
	
	SDLImage::SDLImage(SDL_Surface* surface, SDLEngine& engine) :
		Image(),
		m_surface(surface),
		m_engine(&engine)
	{
	}
	
	SDLImage::~SDLImage()
	{
		if (m_surface) {
			SDL_FreeSurface(m_surface);
		}
	}
	
	SDL_Surface* SDLImage::getSurface()
	{
		return m_surface;
	}
	
	void SDLImage::draw(int x, int y)
	{
		m_engine->drawSurface(m_surface, x, y);
	}
	
	int SDLImage::getWidth()
	{
		return m_surface->w;
	}
	
	int SDLImage::getHeight()
	{
		return m_surface->h;
	}
};
