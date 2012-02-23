#ifndef __BLOCKWORLD_PLAYER_H__
#define __BLOCKWORLD_PLAYER_H__

#include "../GameObject.h"

#include "../../Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class Player : public GameObject {
		public:
			Player(Engine& engine, World& world, int x, int y);
			virtual ~Player();
	};
};

#endif // __BLOCKWORLD_PLAYER_H__
