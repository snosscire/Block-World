#ifndef __BLOCKWORLD_DIRTBLOCK_H__
#define __BLOCKWORLD_DIRTBLOCK_H__

#include "../../Block.h"

namespace BlockWorld {
	class DirtBlock : public Block {
		private:
			DirtBlock();
		
		public:
			DirtBlock(World&, int x, int y);
			virtual ~DirtBlock();
	};
};

#endif // __BLOCKWORLD_DIRTBLOCK_H__
