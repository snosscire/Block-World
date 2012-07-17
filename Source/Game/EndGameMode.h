#ifndef __BLOCKWORLD_ENDGAMEMODE_H__
#define __BLOCKWORLD_ENDGAMEMODE_H__

#include "../Engine/BitmapFont.h"
#include "../Engine/Image.h"
#include "../Engine/EventObserver.h"

#include "GameMode.h"

#include <string>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class EndGameMode : public GameMode, public EventObserver {
		private:
			Image* m_background;
			string m_winner;
			BitmapFont* m_font;
			
		private:
			EndGameMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
		public:
			EndGameMode(Game* game);
			~EndGameMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
			void setWinner(string winner);
	};
};

#endif //  __BLOCKWORLD_NOTHINGMODE_H__
