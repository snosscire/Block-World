#include "DefaultBlockFactory.h"
#include "BlockType.h"
#include "World.h"
#include "Blocks/Default/StoneBlock.h"
#include "Blocks/Default/DirtBlock.h"

#include <iostream>

namespace BlockWorld {
	DefaultBlockFactory::DefaultBlockFactory() :
		BlockFactory()
	{
	}
	
	DefaultBlockFactory::~DefaultBlockFactory()
	{
	}
	
	Block* DefaultBlockFactory::createBlock(BlockType type, World& world, int x, int y)
	{
		switch (type) {
			case BLOCK_TYPE_STONE: return new StoneBlock(world, x, y);
			case BLOCK_TYPE_DIRT:  return new DirtBlock(world, x, y);
		}
		return NULL;
	}
};
