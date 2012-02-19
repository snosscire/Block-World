#include "WorldGenerator.h"
#include "World.h"
#include "Block.h"
#include "BlockFactory.h"

#include <iostream>

namespace BlockWorld {
	WorldGenerator::WorldGenerator()
	{
	}
	
	WorldGenerator::~WorldGenerator()
	{
	}
	
	World* WorldGenerator::createWorld(Engine& engine, BlockFactory& blockFactory, unsigned int width, unsigned int height)
	{
		World* world = new World(width, height);
		
		int limitUp = world->getHeight() * 0.65;
		int limitDown = world->getHeight() * 0.45;
		
		int x = 0;
		int y = engine.getRandomNumber(limitDown, limitUp);
				
		int lastY = y;
		int blocksInRow = 0;
				
		world->setBlock(x, y, blockFactory.createBlock(BLOCK_TYPE_DIRT, *world, x, y));
		
		for (x = 0; x < world->getWidth(); x++) {
			int randomNumber = engine.getRandomNumber(1, 100);
			y = lastY;
			
			if (blocksInRow >= 1) {
				if (y >= limitUp) {
					y = lastY - 1;
					blocksInRow = 0;
				} else if (y <= limitDown) {
					y = lastY + 1;
					blocksInRow = 0;
				} else {
					if (randomNumber > 66) {
						y = lastY + 1;
						blocksInRow = 0;
					} else if (randomNumber < 33) {
						y = lastY - 1;
						blocksInRow = 0;
					} else {
						blocksInRow++;
					}
				}
			} else {
				blocksInRow++;
			}
			
			world->setBlock(x, y, blockFactory.createBlock(BLOCK_TYPE_DIRT, *world, x, y));
			
			lastY = y;
		}
				
		bool foundGroundStart = false;
				
		for (int x = 0; x < world->getWidth(); x++) {
			foundGroundStart = false;
			
			for (int y = 0; y < world->getHeight(); y++) {				
				if (!foundGroundStart) {
					Block *block = world->getBlock(x, y);
					if( block && block->getType() == BLOCK_TYPE_DIRT)
					{
						foundGroundStart = true;
						continue;
					}
					continue;
				}
				
				world->setBlock(x, y, blockFactory.createBlock(BLOCK_TYPE_DIRT, *world, x, y));				
			}
		}
		
		return world;
	}
}
