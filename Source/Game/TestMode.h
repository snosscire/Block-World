#ifndef __BLOCKWORLD_TESTMODE_H__
#define __BLOCKWORLD_TESTMODE_H__

#include "../Engine/GameMode.h"
#include "../Engine/EventObserver.h"
#include "../Engine/Camera.h"

#include "World.h"

using namespace BadEngine;

namespace BlockWorld {
	class World;
	class TestMode : public GameMode, public EventObserver {
		private:
			World* m_world;
			Camera* m_camera;
		
		private:
			TestMode();
			void performStart();
			void performStop();
			void performUpdate();
			void performDraw();
			
		public:
			TestMode(Game* game);
			~TestMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_TESTMODE_H__
