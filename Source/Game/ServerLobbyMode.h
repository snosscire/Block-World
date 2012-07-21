#ifndef __BLOCKWORLD_SERVERLOBBYMODE_H__
#define __BLOCKWORLD_SERVERLOBBYMODE_H__

#include "../Engine/Square.h"
#include "../Engine/BitmapFont.h"
#include "../Engine/Image.h"
#include "../Engine/EventObserver.h"

#include "GameMode.h"

#include <string>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class ServerLobbyMode : public GameMode, public EventObserver {
		private:
			Image* m_background;
			BitmapFont* m_font;
			string m_host;
			
		private:
			ServerLobbyMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
			void drawItem(int x, int y, string name);
			
		public:
			ServerLobbyMode(Game* game);
			~ServerLobbyMode();
			void setHost(string host);
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
			void onMouseButtonDown(MouseButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_SERVERLISTMODE_H__
