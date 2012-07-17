#ifndef __BLOCKWORLD_SPLASHMODE_H__
#define __BLOCKWORLD_SPLASHMODE_H__

#include "../Engine/Image.h"
#include "../Engine/EventObserver.h"

#include "GameMode.h"

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class SplashMode : public GameMode, public EventObserver {
		private:
			Image* m_background;
			
		private:
			SplashMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
		public:
			SplashMode(Game* game);
			~SplashMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_NOTHINGMODE_H__
