#ifndef __WORLDGENERATOR_H__
#define __WORLDGENERATOR_H__

#include "Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class World;
	class BlockFactory;
	class WorldGenerator {
		public:
			WorldGenerator();
			~WorldGenerator();
			World* createWorld(Engine& engine, BlockFactory& blockFactory, unsigned int width, unsigned int height);
	};
};

#endif // __WORLDGENERATOR_H__
