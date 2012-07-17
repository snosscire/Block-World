#ifndef __BLOCKWORLD_SERVERLISTMODE_H__
#define __BLOCKWORLD_SERVERLISTMODE_H__

#include "../Engine/Square.h"
#include "../Engine/BitmapFont.h"
#include "../Engine/Image.h"
#include "../Engine/EventObserver.h"

#include "GameMode.h"

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class ServerListMode : public GameMode, public EventObserver {
		private:
			Image* m_background;
			BitmapFont* m_font;
			Image* m_joinButton;
			Image* m_joinButtonClick;
			Square* m_joinButtonRect;
			
		private:
			ServerListMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
			void drawItem(int x, int y, string name);
			
		public:
			ServerListMode(Game* game);
			~ServerListMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
			void onMouseButtonDown(MouseButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_SERVERLISTMODE_H__
