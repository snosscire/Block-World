#include "World.h"
#include "WorldBackground.h"
#include "BlockWorld.h"
#include "Block.h"
#include "Camera.h"

#include "../Engine/Square.h"

#include <iostream>

namespace BlockWorld {
	bool compareWorldBackgroundLayers(WorldBackground* first, WorldBackground* second)
	{
		if (first->getLayer() < second->getLayer()) {
			return true;
		}
		return false;
	}
	
	World::World() :
		m_width(0),
		m_height(0),
		m_backgrounds(),
		m_blocks(NULL)
	{
	}
	
	World::World(int width, int height) :
		m_width(width),
		m_height(height),
		m_backgrounds(),
		m_blocks(NULL)
	{
		m_blocks = new Block**[m_width];
		
		for (int x = 0; x < m_width; x++) {
			m_blocks[x] = new Block*[m_height];
			
			for (int y = 0; y < m_height; y++) {
				m_blocks[x][y] = NULL;
			}
			
		}
	}
	
	World::~World()
	{		
		for (int x = 0; x < m_width; x++) {
			for(int y = 0; y < m_height; y++ ) {
				delete m_blocks[x][y];
			}
			delete[] m_blocks[x];
		}
		delete[] m_blocks;

		list<WorldBackground*>::iterator it;
		it = m_backgrounds.begin();
		for ( ; it != m_backgrounds.end(); it++) {
			WorldBackground* background = *it;
			delete background;
		}

	}
	
	int World::getWidth()
	{
		return m_width;
	}
	
	int World::getHeight()
	{
		return m_height;
	}
	
	void World::addBackground(WorldBackground* background)
	{
		m_backgrounds.push_back(background);
		m_backgrounds.sort(BlockWorld::compareWorldBackgroundLayers);
	}
	
	void World::setBlock(int x, int y, Block* newBlock)
	{
		if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
			Block* oldBlock = getBlock(x, y);
			if (oldBlock) {
				delete oldBlock;
			}
			m_blocks[x][y] = newBlock;
		}
	}
	
	Block* World::getBlock(int x, int y)
	{
		if (x >= 0 && x < m_width && y >= 0 && y < m_height)
		{
			return m_blocks[x][y];
		}
		return NULL;
	}
	
	void World::draw(Engine& engine, Camera& camera)
	{
		//Square backgroundRectangle(0, 0, engine.getScreenWidth(), engine.getScreenHeight());
		
		int left = camera.getLeft() / BlockWorld::BLOCK_WIDTH;
		int right = camera.getRight() / BlockWorld::BLOCK_WIDTH;
		int top = camera.getTop() / BlockWorld::BLOCK_HEIGHT;
		int bottom = camera.getBottom() / BlockWorld::BLOCK_HEIGHT;
		
		WorldBackground* background = NULL;
		
		list<WorldBackground*>::iterator it = m_backgrounds.begin();
		for ( ; it != m_backgrounds.end(); it++) {
			background = *it;
			background->draw(engine, camera);
		}
				
		Block *block = NULL;
						
		//engine.drawSquare(backgroundRectangle, 50, 150, 200);
		
		for (int x = left; x <= right; x++) {
			for (int y = top; y <= bottom; y++) {
				block = getBlock(x, y);
				if (block) {
					block->draw(engine, camera);
				}
			}
		}
		
	}
	
	bool World::_haveCollision(Square& a, Square& b)
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
	
	Block* World::haveCollision(int x, int y, int width, int height)
	{
		bool haveCollision = false;
		Block* collisionBlock = NULL;
		list<Block*> blocks;
		
		int iStart = x - BlockWorld::BLOCK_WIDTH;
		int iEnd = x + width + BlockWorld::BLOCK_WIDTH;
		
		for (int i = iStart; i <= iEnd; i += BlockWorld::BLOCK_WIDTH) {
			int blockX = i / BlockWorld::BLOCK_WIDTH;
			
			int jStart = y - BlockWorld::BLOCK_HEIGHT;
			int jEnd = y + height + BlockWorld::BLOCK_HEIGHT;
			
			for (int j = jStart; j <= jEnd; j += BlockWorld::BLOCK_HEIGHT) {
				int blockY = j / BlockWorld::BLOCK_HEIGHT;
				Block *block = getBlock(blockX, blockY);
				if (block) {
					blocks.push_back(block);
				}
			}
		}
		
		Square objectRectangle(x, y, width, height);
		
		list<Block*>::iterator it = blocks.begin();
		
		for ( ; it != blocks.end(); it++) {
			Block* block = *it;
			
			Square blockRectangle;
			blockRectangle.setX(block->getX() * BlockWorld::BLOCK_WIDTH);
			blockRectangle.setY(block->getY() * BlockWorld::BLOCK_HEIGHT);
			blockRectangle.setWidth(BlockWorld::BLOCK_WIDTH);
			blockRectangle.setHeight(BlockWorld::BLOCK_HEIGHT);
			
			if (_haveCollision(objectRectangle, blockRectangle)) {
				haveCollision = true;
				collisionBlock = block;
				break;
			}
		}
				
		return collisionBlock;
	}
	
	void World::getWorldPositionFromScreenPosition(Camera& camera, Position& screenPosition, Position& worldPosition)
	{
		worldPosition.setX((screenPosition.getX() + camera.getLeft()) / BlockWorld::BLOCK_WIDTH);
		worldPosition.setY((screenPosition.getY() + camera.getTop()) / BlockWorld::BLOCK_HEIGHT);
	}
	
	Block* World::takeBlock(int x, int y)
	{
		Block* block = getBlock(x, y);
		if (block) {
			m_blocks[x][y] = NULL;
		}
		return block;
	}
	
	Position* World::getRandomOpenPosition(Engine& engine, int width, int height)
	{
		int x = 0;
		int y = 0;
		do {
			x = engine.getRandomNumber(0, m_width * BlockWorld::BLOCK_WIDTH);
			y = engine.getRandomNumber(0, m_height * BlockWorld::BLOCK_HEIGHT);
		} while (haveCollision(x, y, width, height));
		
		Position* position = new Position(x, y);
		return position;
	}
};
