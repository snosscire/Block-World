#ifndef __WORLDGENERATOR_H__
#define __WORLDGENERATOR_H__

#include "BlockType.h"

namespace BlockWorld {
	class World;
	class WorldGenerator {
		public:
			WorldGenerator();
			~WorldGenerator();
			void registerBlock(BlockType type);
			World* createWorld(unsigned int width, unsigned int height);
	};
};

#endif // __WORLDGENERATOR_H__
