#ifndef __BLOCKWORLD_WEAPON_H__
#define __BLOCKWORLD_WEAPON_H__

#include "../Engine/Engine.h"
#include "../Engine/Image.h"

#include <list>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class Bullet;
	class GameObject;
	class GameNetworkClient;
	class Weapon {
		protected:
			GameObject* m_owner;
			Image* m_image;
			list<Bullet*> m_bullets;
		
		private:
			Weapon();
		
		protected:
			Weapon(GameObject& owner);
		
		public:
			virtual ~Weapon();
			void updateBullets(double currentTime, double deltaTime, GameNetworkClient* network);
			virtual void update(double currentTime, double deltaTime, GameNetworkClient* network) { }
			void drawBullets(Engine& engine, Camera& camera);
			void draw(Engine& engine, Camera& camera);
			virtual void startFiring() = 0;
			virtual void stopFiring() = 0;
			virtual void fireBullet(double x, double y, double angle) = 0;
	};
};

#endif
