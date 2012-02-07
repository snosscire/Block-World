#include "DirtBlock.h"

namespace BlockWorld {
	DirtBlock::DirtBlock() :
		Block()
	{
	}
	
	DirtBlock::DirtBlock(World& world, unsigned int x, unsigned int y) :
		Block(world, x, y)
	{
		m_type = BLOCK_TYPE_DIRT;
	}
	
	DirtBlock::~DirtBlock()
	{
	}
};
