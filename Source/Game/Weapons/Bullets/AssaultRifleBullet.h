#ifndef __BLOCKWORLD_ASSAULTRIFLEBULLET_H__
#define __BLOCKWORLD_ASSAULTRIFLEBULLET_H__

#include "../../Bullet.h"

namespace BlockWorld {
	class World;
	class GameObject;
	class Block;
	class AssaultRifleBullet : public Bullet {
		public:
			AssaultRifleBullet(Engine& engine, World& world, GameObject& owner, double x, double y, double angle);
			virtual ~AssaultRifleBullet();
			void doDamage(GameObject& object);
			void doDamage(Block& object);
	};
};

#endif
