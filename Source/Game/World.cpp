#include "World.h"
#include "BlockWorld.h"
#include "Block.h"
#include "Camera.h"

#include "../Engine/Rectangle.h"

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
	
	void World::draw(Engine& engine, Camera& camera)
	{
		Rectangle backgroundRectangle(0, 0, engine.getScreenWidth(), engine.getScreenHeight());
		
		unsigned int left = camera.getLeft() / BlockWorld::BLOCK_WIDTH;
		unsigned int right = camera.getRight() / BlockWorld::BLOCK_WIDTH;
		unsigned int top = camera.getTop() / BlockWorld::BLOCK_HEIGHT;
		unsigned int bottom = camera.getBottom() / BlockWorld::BLOCK_HEIGHT;
				
		Block *block = NULL;
						
		engine.drawRectangle(backgroundRectangle, 50, 150, 200);
		
		for (unsigned int x = left; x <= right; x++) {
			for (unsigned int y = top; y <= bottom; y++) {
				block = getBlock(x, y);
				if (block) {
					block->draw(engine, camera);
				}
			}
		}
		
	}
	
	bool World::_haveCollision(Rectangle& a, Rectangle& b)
	{
		int aLeft = a.getX();
		int aRight = a.getX() + a.getWidth();
		int aTop = a.getY();
		int aBottom = a.getY() + a.getHeight();
		int bLeft = b.getX();
		int bRight = b.getX() + b.getWidth();
		int bTop = b.getY();
		int bBottom = b.getY() + b.getHeight();
		if (aBottom <= bTop) {
			return false;
		}
		if ( aTop >= bBottom) {
			return false;
		}
		if (aRight <= bLeft) {
			return false;
		}
		if( aLeft >= bRight ) {
			return false;
		}
		return true;
	}
	
	bool World::haveCollision(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		bool haveCollision = false;
		list<Block*> blocks;
		
		for (unsigned int i = x; i <= (x + width); i++) {
			unsigned int blockX = i / BlockWorld::BLOCK_WIDTH;
			
			for (unsigned int j = y; j <= (y + height); j++) {
				unsigned int blockY = j / BlockWorld::BLOCK_HEIGHT;
				
				//printf("block_x: %d\n", block_x);
				//printf("block_y: %d\n", block_y);
				
				Block *block = getBlock(blockX, blockY);
				
				if (block) {
					//printf("Found block\n");
					blocks.push_back(block);
				}
			}
		}
		
		Rectangle objectRectangle(x, y, width, height);
		
		list<Block*>::iterator it = blocks.begin();
		
		for ( ; it != blocks.end(); it++) {
			Block* block = *it;
			Rectangle blockRectangle;
			blockRectangle.setX(block->getX() * BlockWorld::BLOCK_WIDTH);
			blockRectangle.setY(block->getY() * BlockWorld::BLOCK_HEIGHT);
			blockRectangle.setWidth(BlockWorld::BLOCK_WIDTH);
			blockRectangle.setHeight(BlockWorld::BLOCK_HEIGHT);
			
			if (_haveCollision(objectRectangle, blockRectangle)) {
				haveCollision = true;
				break;
			}
		}
				
		return haveCollision;
	}
	
	void World::getWorldPositionFromScreenPosition(Camera& camera, Position& screenPosition, Position& worldPosition)
	{
		worldPosition.setX((screenPosition.getX() + camera.getLeft()) / BlockWorld::BLOCK_WIDTH);
		worldPosition.setY((screenPosition.getY() + camera.getTop()) / BlockWorld::BLOCK_HEIGHT);
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
