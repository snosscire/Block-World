#ifndef __BLOCKWORLD_NOTHINGMODE_H__
#define __BLOCKWORLD_NOTHINGMODE_H__

#include "../Engine/EventObserver.h"

#include "GameMode.h"

using namespace BadEngine;

namespace BlockWorld {
	class NothingMode : public GameMode, public EventObserver {
		
		private:
			NothingMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
		public:
			NothingMode(Game* game);
			~NothingMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_NOTHINGMODE_H__
