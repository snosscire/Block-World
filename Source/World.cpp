#include "World.h"
#include "BlockWorld.h"
#include "Block.h"
#include "Camera.h"

#include <iostream>

namespace BlockWorld {
	World::World() :
		m_width(0),
		m_height(0),
		m_blocks(NULL)
	{
	}
	
	World::World(unsigned int width, unsigned int height) :
		m_width(width),
		m_height(height),
		m_blocks(NULL)
	{
		//m_blocks = malloc(sizeof(Block*) * m_width);
		m_blocks = new Block**[m_width];
		
		for (unsigned int x = 0; x < m_width; x++) {
			//m_blocks[x] = malloc(sizeof(Block*) * m_height);
			m_blocks[x] = new Block*[m_height];
			
			for (unsigned int y = 0; y < m_height; y++) {
				m_blocks[x][y] = NULL;
			}
			
		}
	}
	
	World::~World()
	{
		for (unsigned int x = 0; x < m_width; x++) {
			for(unsigned int y = 0; y < m_height; y++ ) {
				//free(m_blocks[x][y]);
				delete m_blocks[x][y];
			}
			//free(m_blocks[x]);
			delete[] m_blocks[x];
		}
		//free(m_blocks);
		delete[] m_blocks;
	}
	
	unsigned int World::getWidth()
	{
		return m_width;
	}
	
	unsigned int World::getHeight()
	{
		return m_height;
	}
	
	void World::setBlock(unsigned int x, unsigned int y, Block* newBlock)
	{
		if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
			Block* oldBlock = getBlock(x, y);
			if (oldBlock) {
				delete oldBlock;
			}
			m_blocks[x][y] = newBlock;
		}
	}
	
	Block* World::getBlock(unsigned int x, unsigned int y)
	{
		if (x >= 0 && x < m_width && y >= 0 && y < m_height)
		{
			return m_blocks[x][y];
		}
		return NULL;
	}
	
	void World::draw(Engine* engine, Camera* camera)
	{
		unsigned int left = camera->getLeft() / BlockWorld::BLOCK_WIDTH;
		unsigned int right = camera->getRight() / BlockWorld::BLOCK_WIDTH;
		unsigned int top = camera->getTop() / BlockWorld::BLOCK_HEIGHT;
		unsigned int bottom = camera->getBottom() / BlockWorld::BLOCK_HEIGHT;
				
		Block *block = NULL;
				
		//engine->drawRectangle(0, 0, engine->getScreenWidth(), engine->getScreenHeight(), 50, 150, 200);
		
		for (unsigned int x = left; x <= right; x++) {
			for (unsigned int y = top; y <= bottom; y++) {
				block = getBlock(x, y);
				if (block) {
					block->draw(engine, camera);
				}
			}
		}
		
	}
	
	bool World::haveCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		return false;
	}
	
	void World::getWorldPositionFromScreenPosition(Camera* camera, unsigned int screenX, unsigned int screenY, unsigned int* worldX, unsigned int* worldY)
	{
		*worldX = (screenX + camera->getLeft()) / BlockWorld::BLOCK_WIDTH;
		*worldY = (screenY + camera->getTop()) / BlockWorld::BLOCK_HEIGHT;
	}
	
	Block* World::takeBlock(unsigned int x, unsigned int y)
	{
		Block* block = getBlock(x, y);
		if (block) {
			m_blocks[x][y] = NULL;
		}
		return block;
	}
};
