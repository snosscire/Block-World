#include "WorldGenerator.h"
#include "World.h"
#include "Block.h"

#include <iostream>
#include <SDL/SDL.h>

namespace BlockWorld {
	WorldGenerator::WorldGenerator()
	{
	}
	
	WorldGenerator::~WorldGenerator()
	{
	}
	
	void WorldGenerator::registerBlock(BlockType type)
	{
	}
	
	World* WorldGenerator::createWorld(Engine& engine, unsigned int width, unsigned int height)
	{
		World* world = new World(width, height);
		
		unsigned int limitUp = world->getHeight() * 0.65;
		unsigned int limitDown = world->getHeight() * 0.45;
		
		unsigned int x = 0;
		unsigned int y = engine.getRandomNumber(limitDown, limitUp);
		
		//MineWorld_SetBlock(world, x, y, MineBlock_Dirt_Create(x, y));
		
		unsigned int lastY = y;
		int blocksInRow = 0;

		Uint32 complete_start;
		Uint32 complete_end;
		Uint32 complete_time;
		
		complete_start = SDL_GetTicks();
		
		world->setBlock(x, y, new Block(*world, x, y));
		
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

			//MineWorld_SetBlock(world, x, y, MineBlock_Dirt_Create(world, x, y));
			world->setBlock(x, y, new Block(*world, x, y)); // DirtBlock
			
			lastY = y;
		}
		
		// Next we are going to go through each position in the world and ask
		// what the probability of a block spawning is based on
		// the surrounding neighbor blocks.
		// Then we are going to calculate which block to create.
		
		/*
		Uint32 start;
		Uint32 end;
		Uint32 time;
		
		List *neighbor_blocks = NULL;
		char found_ground_start = FALSE;
		
		//unsigned int world_width = ;
		//unsigned int world_height = ;
		
		for( x = 0; x < MineWorld_GetWidth(world); x++ )
		{
			found_ground_start = FALSE;
			
			for( y = 0; y < MineWorld_GetHeight(world); y++ )
			{
				//printf("Creating block: %d,%d\n", x, y);
				
				if( NOT found_ground_start )
				{
					Block *block = MineWorld_GetBlock(world, x, y);
					if( block AND MineBlock_GetType(block) == MINE_BLOCK_TYPE_DIRT )
					{
						found_ground_start = TRUE;
						continue;
					}
					continue;
				}
				
				start = SDL_GetTicks();
				
				// Empty the list of neighbor blocks
				//if( neighbor_blocks )
				//	MineList_Destroy(neighbor_blocks);
				//neighbor_blocks = MineList_Create(NULL);
				
				end = SDL_GetTicks();
				time = end - start;
				//printf("Clear list: %d\n", time);
				
				// Get the neighbor blocks
				Block *neighbor_block = NULL;
				
				start = SDL_GetTicks();
				
				Block *neighbor_left = MineWorld_GetBlock(world, x - 1, y);
				Block *neighbor_right = MineWorld_GetBlock(world, x + 1, y);
				Block *neighbor_top = MineWorld_GetBlock(world, x, y - 1);
				Block *neighbor_bottom = MineWorld_GetBlock(world, x, y + 1);
				
				//neighbor_block = MineWorld_GetBlock(world, x - 1, y - 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x - 1, y);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x - 1, y + 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x, y - 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x, y + 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x + 1, y - 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x + 1, y);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				//neighbor_block = MineWorld_GetBlock(world, x + 1, y + 1);
				//if( neighbor_block )
				//	MineList_Append(neighbor_blocks, neighbor_block);
				
				end = SDL_GetTicks();
				time = end - start;
				//printf("Get neighbor blocks: %d\n", time);
				
				// Go through the registered blocks
				
				start = SDL_GetTicks();
				
				//FOREACH(MineWorldGenerator_RegisteredBlocks, RegisteredBlock, block)
				//	int probability = block->spawn_probability(neighbor_blocks);
				//	int random_number = MineEngine_RandomNumber(1, 100);
				//	if( random_number <= probability )
				//	{
				//		//printf("Setting block: %d\n", block->type);
				//		MineWorld_SetBlock(world, x, y, block->create(x, y));
				//		break;
				//	}
				//ENDFOREACH
				
				List *probabilities = MineList_Create(free);
				int number = 0;
				
				FOREACH(MineWorldGenerator_RegisteredBlocks,  RegisteredBlock, block)
					Probability *probability = malloc(sizeof(Probability));
					probability->block = block;
					probability->low = number + 1;
					probability->high = number + block->spawn_probability(neighbor_left, neighbor_right, neighbor_top, neighbor_bottom);
					number = probability->high;
					MineList_Append(probabilities, probability);
				ENDFOREACH
				
				int random_number = MineEngine_RandomNumber(1, number);
				
				FOREACH(probabilities, Probability, probability)
					if( random_number >= probability->low AND random_number <= probability->high )
					{
						MineWorld_SetBlock(world, x, y, probability->block->create(world, x, y));
						break;
					}
				ENDFOREACH
				
				MineList_Destroy(probabilities);
				
				end = SDL_GetTicks();
				time = end - start;
				
				//printf("Loop registered blocks: %d\n", time);
			}
		}
		*/
		
		complete_end = SDL_GetTicks();
		complete_time = complete_end - complete_start;
		
		printf("Complete: %d\n", complete_time);
		
		return world;
	}
}
