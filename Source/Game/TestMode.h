#ifndef __BLOCKWORLD_TESTMODE_H__
#define __BLOCKWORLD_TESTMODE_H__

#include "../Engine/EventObserver.h"

#include "GameMode.h"
#include "World.h"

#include <deque>

using namespace BadEngine;
using namespace std;

namespace BlockWorld {
	class MapDirectory;
	class Camera;
	class World;
	class GameObject;
	class Crosshair;
	class GibResourceLoader;
	class Weapon;
	class TestMode : public GameMode, public EventObserver {
		private:
			MapDirectory* m_map;
			World* m_world;
			Camera* m_camera;
			GameObject* m_player;
			Crosshair* m_crosshair;
			GibResourceLoader* m_gibLoader;
			deque<GameObject*> m_gibs;
			Weapon* m_weapon;
		
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
