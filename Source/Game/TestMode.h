#ifndef __BLOCKWORLD_TESTMODE_H__
#define __BLOCKWORLD_TESTMODE_H__

#include "../Engine/EventObserver.h"

#include "GameMode.h"
#include "World.h"

using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class World;
	class Player;
	class TestMode : public GameMode, public EventObserver {
		private:
			World* m_world;
			Camera* m_camera;
			Player* m_player;
		
		private:
			TestMode();
			void performStart();
			void performStop();
			void performUpdate(unsigned int deltaTime);
			void performDraw();
			
		public:
			TestMode(Game* game);
			~TestMode();
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_TESTMODE_H__
