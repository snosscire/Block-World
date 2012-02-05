#ifndef __WORLDGENERATOR_H__
#define __WORLDGENERATOR_H__

#include "Engine/Engine.h"
#include "BlockType.h"

using namespace BadEngine;

namespace BlockWorld {
	class World;
	class WorldGenerator {
		public:
			WorldGenerator();
			~WorldGenerator();
			void registerBlock(BlockType type);
			World* createWorld(Engine& engine, unsigned int width, unsigned int height);
	};
};

#endif // __WORLDGENERATOR_H__
