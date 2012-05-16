#ifndef __BLOCKWORLD_TESTMODE_H__
#define __BLOCKWORLD_TESTMODE_H__

#include "../Engine/EventObserver.h"

#include "GameMode.h"
#include "World.h"

using namespace BadEngine;

namespace BlockWorld {
	class MapDirectory;
	class Camera;
	class World;
	class Player;
	class Crosshair;
	class TestMode : public GameMode, public EventObserver {
		private:
			MapDirectory* m_map;
			World* m_world;
			Camera* m_camera;
			Player* m_player;
			Crosshair* m_crosshair;
		
		private:
			TestMode();
			void performStart();
			void performStop();
			void performUpdate(double currentTime, double deltaTime);
			void performDraw();
			
		public:
			TestMode(Game* game);
			~TestMode();
			void setMap(MapDirectory* map);
			void onKeyboardButtonDown(KeyboardButtonEvent& event);
	};
};

#endif //  __BLOCKWORLD_TESTMODE_H__
