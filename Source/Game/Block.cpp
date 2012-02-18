#include "Block.h"
#include "BlockWorld.h"
#include "World.h"
#include "Camera.h"

#include "../Engine/Engine.h"
#include "../Engine/Rectangle.h"

#include <iostream>

namespace BlockWorld {
	Block::Block() :
		m_type(BLOCK_TYPE_DIRT),
		m_position(),
		m_world(NULL)
	{
	}
	
	Block::Block(World& world, unsigned int x, unsigned int y) :
		m_type(BLOCK_TYPE_DIRT),
		m_position(x, y),
		m_world(&world)
	{
	}
	
	Block::~Block()
	{
	}
	
	BlockType Block::getType()
	{
		return m_type;
	}
	
	unsigned int Block::getX()
	{
		return m_position.getX();
	}
	
	unsigned int Block::getY()
	{
		return m_position.getY();
	}
	
	void Block::setPosition(unsigned int x, unsigned int y)
	{
		m_position.setX(x);
		m_position.setY(y);
	}
		
	void Block::update()
	{
	}
	
	void Block::draw(Engine& engine, Camera& camera)
	{
		unsigned int x = (m_position.getX() * BlockWorld::BLOCK_WIDTH) - camera.getLeft();
		unsigned int y = (m_position.getY() * BlockWorld::BLOCK_HEIGHT) - camera.getTop();
		Rectangle rectangle(x, y, BLOCK_WIDTH, BLOCK_HEIGHT);
		engine.drawRectangle(rectangle, 255, 255, 255);
	}
};
