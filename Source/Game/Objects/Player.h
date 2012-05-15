#ifndef __BLOCKWORLD_PLAYER_H__
#define __BLOCKWORLD_PLAYER_H__

#include "../GameObject.h"

#include "../../Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class Player : public GameObject {
		private:
			void initialize(Engine& engine, double x, double y);
		
		public:
			Player(Engine& engine, World& world, double x, double y);
			Player(int networkID, Engine& engine, World& world, double x, double y);
			virtual ~Player();
	};
};

#endif // __BLOCKWORLD_PLAYER_H__
