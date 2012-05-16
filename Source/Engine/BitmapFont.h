#ifndef __BADENGINE_BITMAPFONT_H__
#define __BADENGINE_BITMAPFONT_H__

#include <SDL/SDL.h>

#include <string>
#include <sstream>

using namespace std;

namespace BadEngine {
	class SDLEngine;
	class BitmapFont {
		private:
			SDLEngine* m_engine;
			int m_width;
			int m_height;
			SDL_Surface* m_surface;
		
		private:
			BitmapFont();
		
		public:
			BitmapFont(SDLEngine& engine, string& path, int width, int height);
			~BitmapFont();
			int getTextWith(string& text);
			int getHeight();
			void drawText(int x, int y, string& text);
			void drawText(int x, int y, ostringstream& text);
	};
};

#endif
