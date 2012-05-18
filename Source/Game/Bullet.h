#ifndef __BLOCKWORLD_BULLET_H__
#define __BLOCKWORLD_BULLET_H__

#include "../Engine/Engine.h"
#include "../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameNetworkClient;
	class World;
	class GameObject;
	class Block;
	class Camera;
	class Bullet {
		protected:
			Image* m_image;
			World* m_world;
			GameObject* m_owner;
			bool m_alive;
			double m_x;
			double m_y;
			double m_angle;
			double m_speed;
		
		public:
			Bullet(Image* image, World& world, GameObject& owner, double x, double y, double angle, double speed);
			virtual ~Bullet();
			bool isAlive();
			void update(double currentTime, double deltaTime, GameNetworkClient* network);
			void draw(Engine& engine, Camera& camera);
			virtual void doDamage(GameObject& object) = 0;
			virtual void doDamage(Block& block) = 0;
		
	};
};

#endif
