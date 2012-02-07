#ifndef __BLOCKWORLD_DEFAULTBLOCKFACTORY_H__
#define __BLOCKWORLD_DEFAULTBLOCKFACTORY_H__

#include "BlockFactory.h"

namespace BlockWorld {
	class DefaultBlockFactory : public BlockFactory {
		public:
			DefaultBlockFactory();
			virtual ~DefaultBlockFactory();
			Block* createBlock(BlockType type, World& world, unsigned int x, unsigned int y);
	};
};

#endif // __BLOCKWORLD_DEFAULTBLOCKFACTORY_H__
