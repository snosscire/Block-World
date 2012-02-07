#include "StoneBlock.h"

namespace BlockWorld {
	StoneBlock::StoneBlock() :
		Block()
	{
	}
	
	StoneBlock::StoneBlock(World& world, unsigned int x, unsigned int y) :
		Block(world, x, y)
	{
		m_type = BLOCK_TYPE_STONE;
	}
	
	StoneBlock::~StoneBlock()
	{
	}
};
