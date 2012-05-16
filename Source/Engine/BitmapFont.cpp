#include "BitmapFont.h"
#include "SDL/SDLEngine.h"

#include <SDL/SDL_image.h>

#include <iostream>

namespace BadEngine {
	BitmapFont::BitmapFont() :
		m_engine(NULL),
		m_width(0),
		m_height(0),
		m_surface(NULL)
	{
	}
	
	BitmapFont::BitmapFont(SDLEngine& engine, string& path, int width, int height) :
		m_engine(&engine),
		m_width(width),
		m_height(height),
		m_surface(IMG_Load(path.c_str()))
	{
	}
	
	BitmapFont::~BitmapFont()
	{
		if (m_surface) {
			SDL_FreeSurface(m_surface);
		}
	}
	
	int BitmapFont::getTextWith(string& text)
	{
		return text.length() * m_width;
	}
	
	int BitmapFont::getHeight()
	{
		return m_height;
	}
	
	void BitmapFont::drawText(int x, int y, string& text)
	{
		if (m_surface) {
			for (unsigned int i = 0; i < text.length(); i++) {
				SDL_Rect src_rect;
				SDL_Rect dest_rect;

				int c = (int)text[i];

				src_rect.x = (c % 16) * m_width;
				src_rect.y = (c / 16) * m_height;
				src_rect.w = m_width;
				src_rect.h = m_height;

				dest_rect.x = x + (i * m_width);
				dest_rect.y = y;
				dest_rect.w = m_width;
				dest_rect.h = m_height;
			
				SDL_BlitSurface(m_surface, &src_rect, m_engine->getVideoSurface(), &dest_rect);
			}
		}
	}
	
	void BitmapFont::drawText(int x, int y, ostringstream& text)
	{
		string t = text.str();
		drawText(x, y, t);
	}
};
