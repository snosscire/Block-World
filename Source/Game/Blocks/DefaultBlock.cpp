#include "DefaultBlock.h"
#include "../BlockWorld.h"
#include "../Camera.h"
#include "../World.h"

namespace BlockWorld {
	DefaultBlock::DefaultBlock() :
		Block()
	{
	}
	
	DefaultBlock::DefaultBlock(World &world, int x, int y, BlockType type, Image& image) :
		Block(world, x, y),
		m_image(&image)
	{
		m_type = type;
	}
	
	DefaultBlock::~DefaultBlock()
	{
	}
	
	void DefaultBlock::draw(Engine& engine, Camera& camera)
	{
		int x = (m_position.getX() * BlockWorld::BLOCK_WIDTH) - camera.getLeft();
		int y = (m_position.getY() * BlockWorld::BLOCK_HEIGHT) - camera.getTop();
		if (m_image) {
			m_image->draw(x, y);
		}
	}
};
