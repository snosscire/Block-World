#ifndef __BLOCKWORLD_ASSAULTRIFLE_H__
#define __BLOCKWORLD_ASSAULTRIFLE_H__

#include "../Weapon.h"
#include "../../Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class GameObject;
	class AssaultRifle : public Weapon {
		public:
			AssaultRifle(Engine& engine, GameObject& owner);
			virtual ~AssaultRifle();
	};
};

#endif
