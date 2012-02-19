#ifndef __BLOCKWORLD_STONEBLOCK_H__
#define __BLOCKWORLD_STONEBLOCK_H__

#include "../../Block.h"

namespace BlockWorld {
	class StoneBlock : public Block {
		private:
			StoneBlock();
		
		public:
			StoneBlock(World& world, int x, int y);
			virtual ~StoneBlock();
	};
};

#endif // __BLOCKWORLD_STONEBLOCK_H__
