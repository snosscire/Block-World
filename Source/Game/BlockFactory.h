#ifndef __BLOCKWORLD_BLOCKFACTORY_H__
#define __BLOCKWORLD_BLOCKFACTORY_H__

#include "BlockType.h"

namespace BlockWorld {
	class Block;
	class World;
	class BlockFactory {
		public:
			BlockFactory() { }
			virtual ~BlockFactory() { }
			virtual Block* createBlock(BlockType type, World& world, int x, int y) = 0;
	};
};

#endif // __BLOCKWORLD_BLOCKFACTORY_H__
